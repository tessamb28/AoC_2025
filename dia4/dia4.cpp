#include <bits/stdc++.h>
using namespace std;

// 8 direcciones de adyacencia
const int dx[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> grid;
    string row;
    while (cin >> row) grid.push_back(row);

    int H = grid.size();
    int W = grid[0].size();

    // MATRIZ de grados
    vector<vector<int>> deg(H, vector<int>(W, 0));
    vector<vector<bool>> alive(H, vector<bool>(W, false));

    // Inicializar alive y grados
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '@') {
                alive[i][j] = true;
                int d = 0;
                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni >= 0 && ni < H && nj >= 0 && nj < W &&
                        grid[ni][nj] == '@') {
                        d++;
                    }
                }
                deg[i][j] = d;
            }
        }
    }

    // COLA DE BFS con todos los que empiezan con grado < 4
    queue<pair<int,int>> q;
    long long removed = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (alive[i][j] && deg[i][j] < 4) {
                q.push({i,j});
                alive[i][j] = false;  // marcar que será eliminado
            }
        }
    }

    // BFS dinámico
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        removed++;

        // Reducir grado de vecinos
        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (!alive[nx][ny]) continue;  // ya eliminado o vacío

            deg[nx][ny]--;

            if (deg[nx][ny] < 4) {
                alive[nx][ny] = false;
                q.push({nx, ny});
            }
        }
    }

    cout << removed << "\n";
    return 0;
}
