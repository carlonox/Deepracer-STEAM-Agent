import asyncio
import os
import edge_tts
from pydub import AudioSegment

VOZ = "es-CO-SalomeNeural" 
TEXTO = "Prueba de texto a voz con pausas naturales. Primera frase corta. ... Y aquí tenemos una segunda frase para probar la detección de silencio del servidor."
ARCHIVO_TEMP = "temp_edge.mp3"
ARCHIVO_FINAL = "audio_prueba.mp3"

async def generar_audio_compatible():
    print("1. Generando audio con edge-tts...")
    comunicador = edge_tts.Communicate(TEXTO, VOZ)
    await comunicador.save(ARCHIVO_TEMP)
    
    print("2. Convirtiendo a PCM 16kHz Mono 16-bit...")
    # Cargar el MP3 temporal generado por edge-tts
    audio = AudioSegment.from_file(ARCHIVO_TEMP, format="mp3")
    
    # Transformar a las especificaciones exactas del servidor
    audio = (
        audio.set_frame_rate(16000)  # 16 kHz
             .set_channels(1)        # Mono
             .set_sample_width(2)    # 16-bit PCM (2 bytes por muestra)
    )
    
    # Guardar como WAV PCM real
    audio.export(ARCHIVO_FINAL, format="wav")
    
    # Limpiar archivo temporal
    if os.path.exists(ARCHIVO_TEMP):
        os.remove(ARCHIVO_TEMP)
        
    print(f"¡Listo! Archivo compatible generado en: {ARCHIVO_FINAL}")

if __name__ == "__main__":
    asyncio.run(generar_audio_compatible())