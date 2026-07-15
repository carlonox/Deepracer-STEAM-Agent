from RealtimeSTT import AudioToTextRecorder

def process_text(text):
    # Solo procesamos si hay texto válido y no es una alucinación
    if text and len(text.strip()) > 0:
        # Filtro adicional para frases comunes de alucinación
        alucinaciones = ["gracias", "por favor", "hola", "sí", "no", "bien"]
        if not any(phrase in text.lower() for phrase in alucinaciones) or len(text) > 10:
            print(text)
            # Aquí agregarías a tu documento
            # append_to_document(text)

if __name__ == "__main__":
    recorder = AudioToTextRecorder(
        model="large-v3",
        language="es",
        compute_type="float32",
        device="cuda",
        
        # 🔑 CONFIGURACIÓN CLAVE PARA EVITAR ALUCINACIONES
        # 1. Activar VAD (Detección de Actividad de Voz)
        vad_filter=True,  # ← MUY IMPORTANTE
        vad_parameters={
            "threshold": 0.5,  # Sensibilidad (0-1, más alto = menos sensible)
            "min_speech_duration_ms": 250,  # Mínimo habla para considerar
            "max_speech_duration_s": 30,    # Máximo de habla continua
            "min_silence_duration_ms": 200, # Silencio para detectar fin
            "speech_pad_ms": 400,           # Padding alrededor del habla
            "window_size_samples": 1024,    # Tamaño de ventana
        },
        
        # 2. Umbrales para descartar transcripciones de baja calidad
        no_speech_threshold=0.6,  # Más alto = más estricto
        logprob_threshold=-1.0,   # Filtra transcripciones con baja probabilidad
        compression_ratio_threshold=2.4,  # Filtra texto repetitivo
        
        # 3. Tiempos para evitar falsas detecciones
        post_speech_silence_duration=1.0,  # Más tiempo antes de procesar
        min_length_of_recording=0.5,       # Ignora grabaciones muy cortas
    )
    
    while True:
        recorder.text(process_text)