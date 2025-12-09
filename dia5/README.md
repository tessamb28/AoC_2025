# Día 5 – Cafeteria

## Descripción
Este ejercicio trabaja con rangos de IDs frescos en formato `L-R`, seguidos por una lista de IDs disponibles.  
El objetivo es determinar cuántos de los IDs disponibles son frescos (parte 1) y cuántos IDs *en total* quedan cubiertos por los rangos fusionados (parte 2).

## 1. Por qué hemos elegido este problema
Este problema era ideal para practicar intervalos, ordenación y búsquedas eficientes, algo muy común en programación competitiva. Nos llamó la atención cómo un problema aparentemente simple puede ocultar detalles importantes.

## 2. Técnica o estructura de datos que se emplean
Usamos ordenación, un vector de pares para almacenar intervalos y búsqueda binaria (upper_bound) para comprobar la pertenencia de un ID. También implementamos una fusión de intervalos.

## 3. Descripción de la resolución del problema
Primero leímos los rangos y los ordenamos. Después los fusionamos para dejar solo los intervalos efectivos. Luego, para cada ID, usamos búsqueda binaria para comprobar si está dentro de algún intervalo resultante. Finalmente, contamos cuántos lo estaban.

## 4. Alternativas
Valoramos usar segment trees o mapas ordenados, pero eran demasiado avanzados para lo que pedía el problema. El método que elegimos era el más claro.

## 5. Valoración personal
El ejercicio reforzó la importancia de entender bien la fusión de intervalos y cómo una buena elección de estructuras hace el código más limpio y eficiente.

## Archivos
- `dia5.cpp` — implementación en C++.
- `input.txt` — entrada utilizada para resolver el problema.

