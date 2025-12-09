# Día 7 – Laboratories

## Descripción
El ejercicio consiste en simular el recorrido de un rayo que entra por la parte superior del mapa en la posición marcada con `S`.

El rayo baja verticalmente y:
- Atraviesa espacios vacíos `.`
- Se detiene al llegar a un divisor `^`
- Un divisor genera dos nuevos rayos que continúan hacia izquierda y derecha
- Los nuevos rayos continúan bajando hasta encontrar otro divisor o salir del mapa

### Parte 1
Se cuenta cuántas veces un divisor genera nuevas divisiones del rayo.

### Parte 2
Cada división del rayo representa una separación de líneas temporales (many-worlds interpretation).  
El objetivo es contar cuántos caminos distintos puede generar el rayo.

## Técnica de clase utilizada
- **Recorridos en grafos en rejilla**: el mapa funciona como un grafo 2D.
- **Simulación de estados**: cada rayo es un estado dentro de la simulación.
- **Estructuras de datos vistas en clase**:
  - `queue` para BFS
  - `set` para evitar duplicados
- También se aplica **Divide y Vencerás** implícito al dividir el rayo en dos ramificaciones.

## Archivos
- `dia7.cpp` — implementación de ambas partes.
- `input.txt` — entrada del ejercicio.

