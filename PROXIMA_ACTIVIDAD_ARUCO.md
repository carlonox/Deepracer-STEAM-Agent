# Próxima actividad: preparar navegación por rutas ArUco

Objetivo: dejar el aula marcada con códigos ArUco para que el carro pueda ubicarse y seguir rutas predefinidas.

## 1. Imprimir códigos ArUco

Imprimir varios códigos ArUco con IDs diferentes.

Recomendación:

- usar diccionario `DICT_6X6_250`;
- imprimir cada código en tamaño visible;
- idealmente usar más de `4 cm x 4 cm` si se quiere detección desde más distancia;
- pegar cada código en una zona fija del aula.

Ejemplo de IDs:

```text
10 = mesa
20 = impresora
30 = salida
40 = zona de carga
```

## 2. Medir el tamaño real del código

Medir el lado impreso del ArUco.

Si mide 4 cm, dejar:

```python
MARKER_SIZE = 0.04
```

Si se imprimen códigos de 8 cm, cambiar a:

```python
MARKER_SIZE = 0.08
```

Este valor es importante para que la distancia estimada sea correcta.

## 3. Asignar nombres a cada código

Editar `controlcamara.py` en la sección:

```python
ARUCO_PLACES = {
    10: {"name": "mesa", "aliases": ["mesa"]},
    20: {"name": "impresora", "aliases": ["impresora"]},
    30: {"name": "salida", "aliases": ["salida", "puerta"]},
}
```

Cada ID debe coincidir con el código impreso.

## 4. Definir las rutas del aula

Editar:

```python
ARUCO_ROUTES = {
    "mesa": ["impresora"],
    "impresora": ["mesa", "salida"],
    "salida": ["impresora"],
}
```

Esto define por dónde puede moverse el carro.

Ejemplo:

```text
mesa -> impresora -> salida
```

Si el carro está en `mesa` y se le dice `ve a salida`, primero irá a `impresora` y luego a `salida`.

## 5. Probar detección sin mover

Antes de quitar el freno:

1. Encender el vehículo.
2. Encender cámara/Smart Connect.
3. Reiniciar backend.
4. Ejecutar:

```powershell
.\.venv\Scripts\python.exe controlcamara.py
```

5. Mostrar un ArUco frente a la cámara.
6. Verificar en pantalla que aparezca:

```text
Ubicacion: mesa
Waypoint: ...
Destino: ...
```

## 6. Probar movimiento con freno controlado

Con el carro en el suelo:

1. Escribir un destino en la terminal:

```text
ve a salida
```

2. Quitar el freno con `ESPACIO`.
3. Observar si se dirige al primer waypoint.
4. Volver a presionar `ESPACIO` si se necesita pausar.
5. Presionar `q` para salir y detener.

## 7. Validar comportamiento esperado

El carro debe:

- detectar el ArUco más cercano;
- inferir su ubicación actual;
- calcular la ruta hacia el destino;
- acercarse al siguiente waypoint;
- pasar al siguiente punto al llegar;
- detenerse al completar la ruta.

## 8. Siguiente mejora

Agregar sensores de distancia con ESP32.

La función preparada para eso es:

```python
update_safety_from_esp32_placeholder(safety)
```

Cuando el ESP32 entregue distancia frontal, se debe llamar:

```python
safety.update_front_distance_cm(distancia_cm)
```

Así el carro podrá pausar si alguien cruza o si hay un obstáculo, y continuar cuando el camino esté despejado.

