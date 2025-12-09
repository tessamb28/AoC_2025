# Día 4 – Printing Department

## Descripción
El ejercicio trabaja sobre una rejilla de caracteres que contiene rollos de papel (`@`).  
Un rollo es accesible si tiene menos de 4 vecinos `@` en las 8 direcciones posibles.

## 1. Por qué hemos elegido este problema
Lo elegimos porque nos permitía trabajar con matrices y sus vecinos, algo muy típico en simulaciones, juegos y muchos problemas reales. Además, exigía entender cómo se comportan los elementos al interactuar con sus alrededores.

## 2. Técnica o estructura de datos que se emplean
Trabajamos con una matriz bidimensional para representar el mapa y recorridos en las 8 direcciones posibles. En la segunda parte usamos una cola (BFS) para eliminar elementos accesibles y actualizar sus vecinos dinámicamente.

## 3. Descripción de la resolución del problema
Primero contamos cuántos rollos (@) están mal colocados porque tienen menos de 4 vecinos. Luego simulamos su retirada usando BFS: cada vez que un rollo queda accesible, lo procesamos y revisamos qué vecinos cambian de estado. El sistema evoluciona casi como una reacción en cadena.

## 4. Alternativas
Pensamos en usar DFS o incluso grafos, pero BFS era la opción más clara para la simulación.

## 5. Valoración personal
El problema fue muy visual y entretenido. Ver cómo los rollos iban desapareciendo y afectando al resto reforzó nuestra intuición sobre BFS. Fue uno de los ejercicios más dinámicos y prácticos.

## Archivos
- `dia4.1.c` — solución de la parte 1.
- `dia4.2.c` — solución de la parte 2.
- `input.txt` — datos del problema.


