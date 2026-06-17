from faster_whisper import WhisperModel
import fastapi
import uvicorn
import python_multipart

app = fastapi.FastAPI()

model_size = "large-v3"

# Run on GPU with FP16
model = WhisperModel(model_size, device="cuda", compute_type="float16")

# or run on GPU with INT8
# model = WhisperModel(model_size, device="cuda", compute_type="int8_float16")
# or run on CPU with INT8
# model = WhisperModel(model_size, device="cpu", compute_type="int8")

def transcribe_audio(file_path):
    segments, info = model.transcribe(file_path, beam_size=5)
    language = info.language
    language_probability = info.language_probability
    transcription = "\n".join([segment.text for segment in segments])

    return {
        "language": language,
        "language_probability": language_probability,
        "transcription": transcription
    }

@app.get("/")
async def root():
    return transcribe_audio("audio.mp3")