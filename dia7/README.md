# Día 7 – Laboratories

## Descripción
El ejercicio consiste en simular el recorrido de un rayo que entra por la parte superior del mapa en la posición marcada con `S`.

El rayo baja verticalmente y:
- Atraviesa espacios vacíos `.`
- Se detiene al llegar a un divisor `^`
- Un divisor genera dos nuevos rayos que continúan hacia izquierda y derecha
- Los nuevos rayos continúan bajando hasta encontrar otro divisor o salir del mapa

## 1. Por qué hemos elegido este problema
Elegimos este problema porque mezcla propagación de rayos, rejillas, bifurcaciones y conteo de caminos. Además, combina BFS, DFS y programación dinámica, técnicas muy usadas y que queríamos practicar.

## 2. Técnica o estructura de datos que se emplean
La primera parte se resolvió con BFS, usando una cola y una matriz de visitados. La segunda parte se resolvió con DFS recursivo junto con memoización para evitar cálculos repetidos.

## 3. Descripción de la resolución del problema
En la primera parte, simulamos la trayectoria del rayo a través de la rejilla. Algunas casillas lo desvían o lo bloquean, así que usamos BFS para explorar todas las posibilidades sin repetir estados. En la segunda parte, cuando los rayos pueden dividirse, usamos DFS con programación dinámica para contar todas las rutas posibles hacia el objetivo sin recalcular estados ya conocidos.

## 4. Alternativas
No encontramos otra forma más eficiente que combinara claridad y buen rendimiento.

## 5. Valoración personal
Este problema nos enseñó a elegir entre BFS, DFS y DP según la necesidad del momento. Fue desafiante, pero aprendimos mucho sobre gestión de estados y eficiencia.

## Archivos
- `dia7.cpp` — implementación de ambas partes.
- `input.txt` — entrada del ejercicio.

