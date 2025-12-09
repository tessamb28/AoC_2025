# Día 2 – Gift Shop

Este ejercicio consiste en detectar IDs inválidos comprobando si están formados por la repetición de un bloque de dígitos.

## Técnica de clase utilizada
Para resolverlo se usa procesamiento de cadenas:
- Comprobación de substrings.
- Detección de patrones repetidos.
- División del número en bloques de igual tamaño para compararlos.
Estas técnicas están relacionadas con el manejo de strings y operaciones vistas en clase.

## Descripción de la solución
Para cada número:
1. Se comprueba si su longitud permite dividirlo en partes iguales.
2. Se comparan esas partes para ver si son idénticas.
3. Si es así, el número es inválido; si no, es válido.

Parte 2 amplía el criterio permitiendo repeticiones múltiples del bloque.

## Archivos incluidos
- `diaa2.cpp` — implementación de la solución.
- `input.txt` — datos de entrada.

