#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include "esp_camera.h"
#include "esp_wifi.h"

namespace {

#include "secrets.h"
constexpr uint16_t kDiscoveryPort = 5001;
constexpr uint16_t kDefaultVideoPort = 5000;
constexpr size_t kChunkPayloadBytes = 1300;
constexpr uint32_t kClientTimeoutMs = 3000;
constexpr uint32_t kFrameIntervalMs = 40;  // 25 FPS maximo.

// ESP32-S3-WROOM N16R8 CAM con conector DVP para OV3660/OV2640.
constexpr int kCamPinPwdn = -1;
constexpr int kCamPinReset = -1;
constexpr int kCamPinXclk = 15;
constexpr int kCamPinSiod = 4;
constexpr int kCamPinSioc = 5;
constexpr int kCamPinD7 = 16;
constexpr int kCamPinD6 = 17;
constexpr int kCamPinD5 = 18;
constexpr int kCamPinD4 = 12;
constexpr int kCamPinD3 = 10;
constexpr int kCamPinD2 = 8;
constexpr int kCamPinD1 = 9;
constexpr int kCamPinD0 = 11;
constexpr int kCamPinVsync = 6;
constexpr int kCamPinHref = 7;
constexpr int kCamPinPclk = 13;

WiFiUDP udp;
IPAddress videoClient;
uint16_t videoPort = kDefaultVideoPort;
uint32_t lastClientMessageMs = 0;
uint32_t lastFrameMs = 0;
uint32_t frameId = 0;

void writeU16Be(uint8_t *destination, uint16_t value) {
  destination[0] = static_cast<uint8_t>(value >> 8);
  destination[1] = static_cast<uint8_t>(value);
}

void writeU32Be(uint8_t *destination, uint32_t value) {
  destination[0] = static_cast<uint8_t>(value >> 24);
  destination[1] = static_cast<uint8_t>(value >> 16);
  destination[2] = static_cast<uint8_t>(value >> 8);
  destination[3] = static_cast<uint8_t>(value);
}

bool initializeCamera() {
  camera_config_t config = {};
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = kCamPinD0;
  config.pin_d1 = kCamPinD1;
  config.pin_d2 = kCamPinD2;
  config.pin_d3 = kCamPinD3;
  config.pin_d4 = kCamPinD4;
  config.pin_d5 = kCamPinD5;
  config.pin_d6 = kCamPinD6;
  config.pin_d7 = kCamPinD7;
  config.pin_xclk = kCamPinXclk;
  config.pin_pclk = kCamPinPclk;
  config.pin_vsync = kCamPinVsync;
  config.pin_href = kCamPinHref;
  config.pin_sccb_sda = kCamPinSiod;
  config.pin_sccb_scl = kCamPinSioc;
  config.pin_pwdn = kCamPinPwdn;
  config.pin_reset = kCamPinReset;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_HVGA;
  config.jpeg_quality = 16;
  config.fb_count = 2;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.grab_mode = CAMERA_GRAB_LATEST;

  const esp_err_t error = esp_camera_init(&config);
  if (error != ESP_OK) {
    Serial.printf("CAMERA_ERROR 0x%x\n", error);
    return false;
  }

  sensor_t *sensor = esp_camera_sensor_get();
  if (sensor != nullptr) {
    Serial.printf(
        "CAMERA_OK PID=0x%04x RES=%dx%d\n",
        sensor->id.PID,
        resolution[FRAMESIZE_HVGA].width,
        resolution[FRAMESIZE_HVGA].height);
  }
  return true;
}

void handleDiscovery() {
  const int packetSize = udp.parsePacket();
  if (packetSize <= 0) {
    return;
  }

  char message[64] = {};
  const int bytesRead = udp.read(
      reinterpret_cast<uint8_t *>(message),
      min(packetSize, static_cast<int>(sizeof(message) - 1)));
  if (bytesRead <= 0 || strncmp(message, "DEEPRACER_DISCOVER", 19) != 0) {
    return;
  }

  unsigned int requestedPort = kDefaultVideoPort;
  sscanf(message, "DEEPRACER_DISCOVER %u", &requestedPort);
  if (requestedPort == 0 || requestedPort > 65535) {
    requestedPort = kDefaultVideoPort;
  }

  const IPAddress sender = udp.remoteIP();
  if (sender != videoClient || requestedPort != videoPort) {
    Serial.printf(
        "CLIENT %s:%u\n",
        sender.toString().c_str(),
        static_cast<unsigned int>(requestedPort));
  }
  videoClient = sender;
  videoPort = static_cast<uint16_t>(requestedPort);
  lastClientMessageMs = millis();
}

void sendFrame(camera_fb_t *frame) {
  const uint16_t chunkCount = static_cast<uint16_t>(
      (frame->len + kChunkPayloadBytes - 1) / kChunkPayloadBytes);
  const uint32_t captureTimestamp = millis();
  uint8_t header[14];

  for (uint16_t chunkIndex = 0; chunkIndex < chunkCount; ++chunkIndex) {
    const size_t offset = static_cast<size_t>(chunkIndex) * kChunkPayloadBytes;
    const uint16_t payloadSize = static_cast<uint16_t>(
        min(kChunkPayloadBytes, frame->len - offset));

    writeU32Be(header, frameId);
    writeU16Be(header + 4, chunkIndex);
    writeU16Be(header + 6, chunkCount);
    writeU16Be(header + 8, payloadSize);
    writeU32Be(header + 10, captureTimestamp);

    if (!udp.beginPacket(videoClient, videoPort)) {
      break;
    }
    udp.write(header, sizeof(header));
    udp.write(frame->buf + offset, payloadSize);
    if (!udp.endPacket()) {
      break;
    }
    delayMicroseconds(120);
  }
  ++frameId;
}

}  // namespace

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("\nBOOT DeepRacer ESP32-S3 Camera UDP");

  if (!psramFound()) {
    Serial.println("FATAL PSRAM_NOT_FOUND");
    return;
  }
  Serial.printf("PSRAM %u bytes\n", ESP.getPsramSize());

  WiFi.mode(WIFI_AP);
  WiFi.setSleep(false);
  esp_wifi_set_ps(WIFI_PS_NONE);
  if (!WiFi.softAP(kApSsid, kApPassword, 6, false, 1)) {
    Serial.println("FATAL WIFI_AP_FAILED");
    return;
  }

  Serial.printf(
      "WIFI SSID=%s IP=%s\n",
      kApSsid,
      WiFi.softAPIP().toString().c_str());

  if (!udp.begin(kDiscoveryPort)) {
    Serial.println("FATAL UDP_BIND_FAILED");
    return;
  }
  Serial.printf("UDP discovery=%u video=%u\n", kDiscoveryPort, kDefaultVideoPort);

  initializeCamera();
}

void loop() {
  handleDiscovery();

  const uint32_t now = millis();
  const bool clientActive =
      videoClient != IPAddress() &&
      static_cast<uint32_t>(now - lastClientMessageMs) <= kClientTimeoutMs;
  if (!clientActive ||
      static_cast<uint32_t>(now - lastFrameMs) < kFrameIntervalMs) {
    delay(1);
    return;
  }

  lastFrameMs = now;
  camera_fb_t *frame = esp_camera_fb_get();
  if (frame == nullptr) {
    Serial.println("CAMERA_CAPTURE_FAILED");
    delay(10);
    return;
  }

  if (frame->format == PIXFORMAT_JPEG && frame->len > 0) {
    sendFrame(frame);
  }
  esp_camera_fb_return(frame);
}
