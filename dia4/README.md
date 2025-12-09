# Día 4 – Printing Department

## Descripción
El ejercicio trabaja sobre una rejilla de caracteres que contiene rollos de papel (`@`).  
Un rollo es accesible si tiene menos de 4 vecinos `@` en las 8 direcciones posibles.

### Parte 1
Se cuenta cuántos rollos cumplen la condición de tener menos de cuatro vecinos.

### Parte 2
Se simula un proceso iterativo tipo BFS:
- Se introducen en una cola los rollos accesibles.
- Cada vez que se elimina uno, disminuye el número de vecinos de los que están alrededor.
- Si algún vecino pasa a tener menos de cuatro, también entra en la cola.

## Técnica de clase utilizada
- **Grafos en rejilla**: cada `@` es un nodo.
- **Grado de un vértice**: número de vecinos alrededor.
- **BFS / cola** para el proceso iterativo de eliminación.
Estas técnicas se han visto en la unidad de grafos.

## Archivos
- `dia4.1.c` — solución de la parte 1.
- `dia4.2.c` — solución de la parte 2.
- `dia4.cpp` — versión alternativa.
- `input.txt` — datos del problema.


