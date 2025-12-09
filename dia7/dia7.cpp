#include <bits/stdc++.h>
using namespace std;

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // leer la rejilla
    vector<string> grid; // rejilla del manifold
    string line; // línea temporal para leer
    while (getline(cin, line)) { // leer hasta EOF
        if (!line.empty() && (line.back() == '\r' || line.back() == '\n')) // manejar CRLF
            line.pop_back(); // eliminar CR o LF al final
        if (!line.empty()) // evitar líneas vacías
            grid.push_back(line); // añadir línea a la rejilla
    }

    int H = (int)grid.size(); // número de filas
    if (H == 0) { // rejilla vacía
        cout << "0\n0\n"; // resultados triviales
        return 0;
    }
    int W = (int)grid[0].size(); // número de columnas

    // buscar la S (posición de entrada del rayo)
    int sr = -1, sc = -1; // coordenadas de S
    for (int r = 0; r < H; ++r) { // recorrer filas
        for (int c = 0; c < W; ++c) { // recorrer columnas
            if (grid[r][c] == 'S') { // encontramos S
                sr = r;// fila de S
                sc = c; // columna de S
            }
        }
    }

    if (sr == -1) { // no se encontró S
        cout << "0\n0\n";
        return 0;
    }
    //parte1
    long long splitsPart1 = 0;

    // usamos BFS con una cola
    queue<pair<int,int>> q;

    // matriz de visitados para no repetir estados
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    if (sr + 1 < H) {
        q.push({sr + 1, sc});
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        //movemos el rayo hacia abajo hasta que salga o encuentre '^'
        while (true) {
            if (r < 0 || r >= H || c < 0 || c >= W) {
                //sale del manifold: el rayo termina aquí.
                break;
            }

            if (visited[r][c]) {
                //ya hemos procesado este estado
                break;
            }
            visited[r][c] = true;

            if (grid[r][c] == '^') {
                // el rayo se parte aquí
                splitsPart1++;

                int nr = r + 1;
                // rayo nuevo a la izquierda
                if (nr < H && c - 1 >= 0) {
                    q.push({nr, c - 1});
                }
                // rayo nuevo a la derecha
                if (nr < H && c + 1 < W) {
                    q.push({nr, c + 1});
                }
                // el rayo original se detiene en el splitter
                break;
            }

            // sigue bajando
            r++;
        }
    }

    // parte 2
    vector<vector<long long>> memo(H, vector<long long>(W, -1));

    function<long long(int,int)> dfs = [&](int r, int c) -> long long {
        // si estamos fuera, la línea temporal termina, 1 línea.
        if (r < 0 || r >= H || c < 0 || c >= W) {
            return 1LL;
        }

        // si ya hemos calculado dfs(r,c), lo reutilizamos.
        if (memo[r][c] != -1) return memo[r][c];

        int cr = r;

        // movemos el rayo hacia abajo hasta que salga o encuentre '^'
        while (true) {
            if (cr < 0 || cr >= H || c < 0 || c >= W) {
                memo[r][c] = 1LL;
                return memo[r][c];
            }

            if (grid[cr][c] == '^') {
                long long total = 0;
                int nr = cr + 1;

                // rama izquierda
                if (nr < 0 || nr >= H || c - 1 < 0 || c - 1 >= W) {
                    total += 1LL;  // la línea termina
                } else {
                    total += dfs(nr, c - 1);
                }

                // rama derecha
                if (nr < 0 || nr >= H || c + 1 < 0 || c + 1 >= W) {
                    total += 1LL;  // la línea termina
                } else {
                    total += dfs(nr, c + 1);
                }

                memo[r][c] = total;
                return memo[r][c];
            }

            cr++;
        }
    };

    long long timelinesPart2 = 0;
    if (sr + 1 >= H) {
        // si S está en la última fila, el rayo sale inmediatamente.
        timelinesPart2 = 1;
    } else {
        timelinesPart2 = dfs(sr + 1, sc);
    }

    // imprimimos resultados: una línea por parte.
    cout << splitsPart1 << "\n";
    cout << timelinesPart2 << "\n";

    return 0;
}
