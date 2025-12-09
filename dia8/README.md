# Día 8 – Playground

## Descripción
Se trabaja con una serie de cajas (nodos) en el espacio 3D, cada una con coordenadas X, Y, Z.  
El objetivo es conectar pares de cajas mediante cuerdas de luz, siempre eligiendo los pares más cercanos.

## 1. Por qué hemos elegido este problema
Nos llamó la atención que trabajaba con puntos en 3D en lugar de una rejilla 2D. También involucraba distancias y construcción automática de grafos, algo que no vemos tan a menudo.

## 2. Técnica o estructura de datos que se emplean
Usamos un vector de puntos en 3D, cálculo de distancia euclidiana, construcción de listas de adyacencia y DFS para recorrer el grafo generado. También analizamos conexiones basadas en la cercanía entre puntos.

## 3. Descripción de la resolución del problema
Primero almacenamos todos los puntos y calculamos las distancias entre ellos para identificar cuáles debían conectarse. Construimos un grafo donde cada arista representa cercanía entre dos puntos. Después usamos DFS para encontrar los componentes conectados y contarlos.

## 4. Alternativas
Se podrían usar otras estructuras avanzadas pero decidimos hacerlo como lo hemos hecho.

## 5. Valoración personal
Fue muy interesante ver cómo puntos en el espacio se agrupan solos en función de su cercanía. Nos ayudó a entender mejor cómo se aplican los grafos.

## Archivos incluidos
- `dia8.1.c` — aproximación en C, parte 1.
- `dia8.2.c` — aproximación en C, parte 2.
- `input.txt` — coordenadas de entrada.

