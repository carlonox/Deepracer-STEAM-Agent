# Resumen final: navegación con ArUco

El sistema quedó enfocado únicamente en navegación por códigos ArUco y rutas predefinidas.

## Archivo principal

El control está en:

```text
controlcamara.py
```

## Qué hace ahora

- Detecta códigos ArUco con la cámara.
- Identifica la ubicación actual usando el ArUco más cercano.
- Permite definir lugares por ID de ArUco, por ejemplo:

```python
ARUCO_PLACES = {
    10: {"name": "mesa", "aliases": ["mesa"]},
    20: {"name": "impresora", "aliases": ["impresora"]},
    30: {"name": "salida", "aliases": ["salida", "puerta"]},
}
```

- Permite definir rutas entre lugares:

```python
ARUCO_ROUTES = {
    "mesa": ["impresora"],
    "impresora": ["mesa", "salida"],
    "salida": ["impresora"],
}
```

- Si se escribe `ve a salida`, el carro calcula una ruta desde su ubicación actual hasta `salida`.
- Ejemplo: si está en `mesa`, la ruta queda:

```text
mesa -> impresora -> salida
```

## Control del vehículo

- `ESPACIO`: quita o pone el freno de mano.
- `q`: sale y detiene el vehículo.
- En la terminal se escriben destinos como:

```text
ve a salida
ve a impresora
ve a mesa
para
```

## Comunicación con backend

El control usa primero un canal TCP local:

```text
127.0.0.1:5003
```

Si TCP no está disponible, usa el backend HTTP:

```text
http://127.0.0.1:5002
```

El backend debe estar reiniciado para exponer el canal TCP.

## Seguridad

Se agregó una capa `SafetyGate` para separar seguridad de navegación.

Actualmente maneja:

- freno manual;
- bloqueo de avance por sensor frontal futuro;
- permiso para retroceder aunque haya obstáculo frontal;
- espera corta después de despejar obstáculo.

La integración futura del ESP32 está preparada en:

```python
update_safety_from_esp32_placeholder(safety)
```

Cuando haya sensores de distancia, esa función deberá llamar:

```python
safety.update_front_distance_cm(distancia_cm)
```

## Parámetros importantes

El ArUco físico actual se configuró como:

```python
MARKER_SIZE = 0.04
```

Esto corresponde a un código de:

```text
4 cm x 4 cm
```

La distancia objetivo actual al marcador es:

```python
TARGET_DISTANCE = 0.32
```

El carro intenta quedar aproximadamente a 30 cm del ArUco, con margen.

