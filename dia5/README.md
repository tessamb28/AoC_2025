# Día 5 – Cafeteria

## Descripción
Este ejercicio trabaja con rangos de IDs frescos en formato `L-R`, seguidos por una lista de IDs disponibles.  
El objetivo es determinar cuántos de los IDs disponibles son frescos (parte 1) y cuántos IDs *en total* quedan cubiertos por los rangos fusionados (parte 2).

## Técnica de clase utilizada
Se aplican dos técnicas estudiadas en clase:

### ✔ Ordenación (Divide y Vencerás)
Los rangos `L-R` se **ordenan por su extremo izquierdo** usando `sort`, que basa su funcionamiento en algoritmos como mergesort/quicksort.

### ✔ Fusión de intervalos
Se recorre la lista ordenada para **unir rangos solapados**, obteniendo intervalos disjuntos.

### ✔ Búsqueda binaria
Para cada ID disponible, se usa `upper_bound` para comprobar en tiempo **O(log n)** si pertenece a alguno de los rangos fusionados.

## Complejidad
- Ordenar rangos: O(n log n)
- Fusionar: O(n)
- Comprobar m IDs: O(m log n)

## Archivos
- `dia5.cpp` — implementación en C++.
- `input.txt` — entrada utilizada para resolver el problema.

