import asyncio
import numpy as np
import sounddevice as sd
from faster_whisper import WhisperModel

# ----------------------------------------------------------------------
# Configuración del Modelo Faster Whisper v3 en CUDA
# ----------------------------------------------------------------------
MODEL_SIZE = "large-v3"
DEVICE = "cuda"
COMPUTE_TYPE = "float16"

print("Cargando modelo Faster Whisper...")
model = WhisperModel(MODEL_SIZE, device=DEVICE, compute_type=COMPUTE_TYPE)
print("Modelo cargado exitosamente en GPU.")

# ----------------------------------------------------------------------
# Parámetros de Audio y Detección de Silencio
# ----------------------------------------------------------------------
SAMPLE_RATE = 16000
ENERGY_THRESHOLD = 0.015       # Sensibilidad del micrófono
SILENCE_DURATION_SEC = 0.7     # Pausa requerida para procesar frase
MIN_SPEECH_DURATION_SEC = 0.8  # Ignorar ruidos muy cortos

FRAME_DURATION_MS = 30
FRAME_SAMPLES = int(SAMPLE_RATE * (FRAME_DURATION_MS / 1000.0))

# ----------------------------------------------------------------------
# Función de Transcripción
# ----------------------------------------------------------------------
async def procesar_y_transcribir(speech_buffer):
    """Procesa el buffer de voz acumulado mediante Faster Whisper."""
    if not speech_buffer:
        return

    full_speech = np.concatenate(speech_buffer)
    speech_duration = len(full_speech) / SAMPLE_RATE

    if speech_duration >= MIN_SPEECH_DURATION_SEC:
        print(f"\n[+] Transcribiendo tramo de {speech_duration:.2f}s de audio...")
        
        # Inferencia asíncrona en GPU
        segments, _ = await asyncio.to_thread(
            model.transcribe,
            full_speech,
            beam_size=5,
            language="es",
            vad_filter=True
        )
        text = " ".join([segment.text for segment in segments]).strip()
        if text:
            print(f"--> TRANSCRIPCIÓN: {text}\n")
        else:
            print("--> (No se detectó texto comprensible)\n")
    else:
        print(f"\n[-] Tramo omitido: demasiado corto ({speech_duration:.2f}s)\n")

# ----------------------------------------------------------------------
# Bucle Principal de Captura de Micrófono
# ----------------------------------------------------------------------
async def main():
    audio_queue = asyncio.Queue()
    loop = asyncio.get_running_loop()

    # Callback invocado por sounddevice cada vez que el micro entrega un marco
    def callback(indata, frames, time_info, status):
        if status:
            print(status, flush=True)
        # Enviar copia de las muestras de audio a la cola asíncrona
        loop.call_soon_threadsafe(audio_queue.put_nowait, indata.copy())

    print("\n[+] Iniciando escucha desde el micrófono local...")
    print("[+] Habla y realiza pausas naturales. Presiona Ctrl+C para salir.\n")

    # Abrir canal de audio a 16kHz, mono, PCM 16-bit
    stream = sd.InputStream(
        samplerate=SAMPLE_RATE,
        channels=1,
        dtype='int16',
        blocksize=FRAME_SAMPLES,
        callback=callback
    )

    speech_buffer = []
    is_speaking = False
    silence_frames = 0
    frame_count = 0

    with stream:
        while True:
            # Esperar el siguiente bloque de audio del micrófono (30 ms)
            chunk = await audio_queue.get()

            # Normalizar PCM int16 a float32 (-1.0 a 1.0)
            audio_frame = chunk.flatten().astype(np.float32) / 32768.0
            rms = float(np.sqrt(np.mean(audio_frame**2)))

            # Monitor en consola en tiempo real
            frame_count += 1
            if frame_count % 10 == 0:
                estado = "VOZ" if rms > ENERGY_THRESHOLD else "SILENCIO"
                print(f"RMS: {rms:.4f} | Estado: {estado} | Buffer: {len(speech_buffer)} frames", end="\r")

            if rms > ENERGY_THRESHOLD:
                is_speaking = True
                silence_frames = 0
                speech_buffer.append(audio_frame)
            else:
                if is_speaking:
                    speech_buffer.append(audio_frame)
                    silence_frames += 1

                    max_silence_frames = int((SILENCE_DURATION_SEC * 1000) / FRAME_DURATION_MS)

                    # Si se detecta la pausa deseada, transcribir
                    if silence_frames >= max_silence_frames:
                        await procesar_y_transcribir(speech_buffer)
                        speech_buffer = []
                        is_speaking = False
                        silence_frames = 0

if __name__ == "__main__":
    try:
        asyncio.run(main())
    except KeyboardInterrupt:
        print("\n\n[-] Escucha de micrófono finalizada.")