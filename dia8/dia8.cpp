#include <bits/stdc++.h>
using namespace std;

/*
    Day 8 – Playground

    Modelado con GRAFOS y estructuras de datos vistas en clase:

    - Cada junction box es un VÉRTICE en 3D: (x, y, z).
    - Entre cada par de vértices (i, j) hay una ARISTA con peso = distancia^2.
    - Ordenamos TODAS las aristas por peso creciente (sort → divide y vencerás).
    - Usamos una estructura DISJOINT SET UNION (Union-Find) para ir uniendo
      componentes, igual que el algoritmo de Kruskal para árboles de expansión.

    Parte 1:
      - Procesamos las 1000 aristas más cortas (1000 pares más cercanos),
        haciendo union(i, j) según DSU (aunque ya estuvieran en el mismo circuito).
      - Después de esas 1000 conexiones:
          * Contamos el tamaño de cada componente (circuito).
          * Cogemos los 3 mayores y multiplicamos sus tamaños.

    Parte 2:
      - Continuamos con el mismo orden de aristas hasta que todo esté
        en un solo componente.
      - La arista que une los últimos dos componentes nos da las dos
        junction boxes finales; devolvemos el producto de sus coordenadas X.
*/

struct DSU { 
    vector<int> parent, rnk, sz; // tamaño de cada componente
    int components; // número de componentes actuales

    DSU(int n = 0) { // constructor
        init(n); // inicializar
    }

    void init(int n) { // inicializar para n elementos
        parent.resize(n); // padre de cada nodo
        rnk.assign(n, 0); // rango (profundidad) de cada árbol
        sz.assign(n, 1); // tamaño de cada componente
        components = n; // inicialmente n componentes
        iota(parent.begin(), parent.end(), 0); // cada nodo es su propio padre
    }

    int find(int x) { // encontrar el representante del conjunto de x
        if (parent[x] != x) // path compression
            parent[x] = find(parent[x]); // recursivo
        return parent[x];// devolver representante
    }

    // devuelve true si se ha hecho una unión nueva
    bool unite(int a, int b) { // unir los conjuntos de a y b
        a = find(a); // encontrar representantes
        b = find(b); // encontrar representantes
        if (a == b) return false; // ya están unidos
        if (rnk[a] < rnk[b]) swap(a, b); // unir b a a
        parent[b] = a; // hacer a el padre de b
        sz[a] += sz[b]; // actualizar tamaño
        if (rnk[a] == rnk[b]) rnk[a]++; // actualizar rango
        components--; // reducir número de componentes
        return true;
    }
    // obtener tamaño del componente de x
    int size(int x) {
        return sz[find(x)];
    }
};
// estructura para representar una arista
struct Edge {
    long long d2; // distancia^2
    int u, v;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // leer las cajas (x,y,z) desde stdin
    vector<array<long long,3>> pts;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        long long x, y, z;
        char c1, c2;
        ss >> x >> c1 >> y >> c2 >> z; // formato: x,y,z
        pts.push_back({x, y, z});
    }

    int n = (int)pts.size();
    if (n == 0) {
        cout << "0\n0\n";
        return 0;
    }

    // construir todas las aristas del grafo completo con peso = distancia^2
    vector<Edge> edges;
    edges.reserve(1LL * n * (n - 1) / 2);

    for (int i = 0; i < n; ++i) {
        auto [x1, y1, z1] = pts[i];
        for (int j = i + 1; j < n; ++j) {
            auto [x2, y2, z2] = pts[j];
            long long dx = x1 - x2;
            long long dy = y1 - y2;
            long long dz = z1 - z2;
            long long d2 = dx*dx + dy*dy + dz*dz;
            edges.push_back({d2, i, j});
        }
    }

    // ordenar las aristas por distancia^2 (divide y vencerás / sort)
    sort(edges.begin(), edges.end(),
         [](const Edge &a, const Edge &b) { return a.d2 < b.d2; });

    //DSU para ir uniendo componentes
    DSU dsu(n);

    long long answerPart1 = 0;
    long long answerPart2 = 0;

    bool gotPart1 = false;
    bool gotPart2 = false;

    int connectionsDone = 0; // número de PARES conectados

    // recorremos aristas en orden creciente 
    for (size_t idx = 0; idx < edges.size() && (!gotPart1 || !gotPart2); ++idx) {
        const auto &e = edges[idx];
        int u = e.u;
        int v = e.v;

        // esta arista cuenta como una conexión, incluso si no cambia los componentes
        connectionsDone++;

        // hacemos la unión, si procede
        bool merged = dsu.unite(u, v);

        // parte 1: justo después de 1000 conexiones (pares más cercanos)
        if (!gotPart1 && connectionsDone == 1000) {
            // contar tamaños de todos los componentes
            unordered_map<int, int> compSize;
            compSize.reserve(n * 2);
            for (int i = 0; i < n; ++i) {
                int root = dsu.find(i);
                compSize[root]++;
            }

            vector<int> sizes;
            sizes.reserve(compSize.size());
            for (auto &kv : compSize) {
                sizes.push_back(kv.second);
            }
            sort(sizes.begin(), sizes.end(), greater<int>());

            long long a = (sizes.size() > 0 ? sizes[0] : 1);
            long long b = (sizes.size() > 1 ? sizes[1] : 1);
            long long c = (sizes.size() > 2 ? sizes[2] : 1);

            answerPart1 = a * b * c;
            gotPart1 = true;
        }

        // parte 2: primera arista que deja el grafo en un solo componente
        if (!gotPart2 && merged && dsu.components == 1) {
            long long x1 = pts[u][0];
            long long x2 = pts[v][0];
            answerPart2 = x1 * x2;
            gotPart2 = true;
        }
    }

    // imprimimos ambas partes 
    cout << "Parte 1: " << answerPart1 << "\n";
    cout << "Parte 2: " << answerPart2 << "\n";

    return 0;
}
