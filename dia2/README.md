# Día 2 – Gift Shop

Este ejercicio consiste en detectar IDs inválidos comprobando si están formados por la repetición de un bloque de dígitos.

## 1. Por qué hemos elegido este problema
Elegimos este problema porque mezcla patrones en cadenas y eficiencia. Nos permitió trabajar con hashing, una técnica que a primera vista parece complicada, pero que hace que las comparaciones entre subcadenas sean sorprendentemente rápidas. También era un buen ejercicio para entender cómo se puede evitar recorrer la cadena completa cada vez que queremos comprobar algo.

## 2. Técnica o estructura de datos que se emplean
Usamos hashing con prefijos (rolling hash), que permite calcular el hash de cualquier subcadena en tiempo constante. La idea de dividir cadenas también está presente, recordando a estrategias de divide y vencerás que ayudan a pensar el problema en partes más pequeñas.

## 3. Descripción de la resolución del problema
Primero convertimos el número a cadena y calculamos el hash de todos sus prefijos. Esto nos permite comparar mitades o bloques completos simplemente comparando números, sin examinar los caracteres uno por uno. Con esto analizamos si el número está formado por la repetición exacta de un bloque dos o más veces.

## 4. Alternativas
No se nos ocurrió otra manera eficaz de hacerlo sin hashing. Otras soluciones posibles requerían comparar subcadenas directamente, lo que habría sido mucho más lento para entradas grandes.

## 5. Valoración personal
Este problema nos ayudó a comprender de verdad la potencia del hashing. Al principio parecía un concepto abstracto, pero al aplicarlo vimos su utilidad. También aprendimos a valorar la eficiencia, no solo el funcionamiento.

## Archivos incluidos
- `diaa2.cpp` — implementación de la solución.
- `input.txt` — datos de entrada.

