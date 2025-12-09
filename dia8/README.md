# Día 8 – Playground

## Descripción
Se trabaja con una serie de cajas (nodos) en el espacio 3D, cada una con coordenadas X, Y, Z.  
El objetivo es conectar pares de cajas mediante cuerdas de luz, siempre eligiendo los pares más cercanos.

### Parte 1
1. Se calculan todas las distancias euclídeas entre cajas.
2. Se ordenan estos pares por distancia creciente.
3. Se realizan las primeras 1000 conexiones.
4. A través de un **Union-Find (estructura vista en clase)** se van uniendo componentes.
5. Finalmente, se obtiene el tamaño de los tres componentes más grandes y se multiplica.

### Parte 2
Se continúa conectando pares hasta que todo el conjunto forme un único componente.  
El resultado final es el producto de las coordenadas X del último par conectado.

## Técnica de clase utilizada
- **Union-Find / Disjoint Set Union (DSU)** para gestionar componentes conectados.
- **Divide y Vencerás**: la ordenación de distancias usa algoritmos tipo mergesort/quicksort.
- **Complejidad**:
  - Cálculo de distancias: O(n²)
  - Ordenación: O(n² log n)
  - Union-Find: casi O(1) por operación

## Archivos incluidos
- `dia8.1.c` — aproximación en C, parte 1.
- `dia8.2.c` — aproximación en C, parte 2.
- `dia8.cpp` — versión en C++ más completa.
- `input.txt` — coordenadas de entrada.

