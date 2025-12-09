#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 2000

// Desplazamientos en las 8 direcciones
static const int dx[8] = {-1,-1,-1,0,0,1,1,1};
static const int dy[8] = {-1,0,1,-1,1,-1,0,1};

typedef struct { int r, c; } Cell;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s archivo.txt\n", argv[0]);
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (!f) { perror("No se pudo abrir archivo"); return 1; }

    // Leer la cuadrícula
    static char grid[MAXN][MAXN];
    int rows = 0, cols = -1;
    while (rows < MAXN && fgets(grid[rows], MAXN, f)) {
        grid[rows][strcspn(grid[rows], "\r\n")] = '\0';
        if (cols == -1) cols = (int)strlen(grid[rows]);
        rows++;
    }
    fclose(f);
    if (rows == 0 || cols <= 0) { printf("0\n"); return 0; }

    // Matrices auxiliares
    static int deg[MAXN][MAXN];      // vecinos '@' alrededor
    static unsigned char isAt[MAXN][MAXN];   // 1 si '@'
    static unsigned char removed[MAXN][MAXN]; // 1 si ya retirado

    // Inicializar isAt y deg
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            isAt[i][j] = (grid[i][j] == '@');
            deg[i][j] = 0;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!isAt[i][j]) continue;
            int cnt = 0;
            for (int d = 0; d < 8; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                    if (isAt[ni][nj]) cnt++;
                }
            }
            deg[i][j] = cnt;
        }
    }

    // Cola de celdas accesibles (deg < 4)
    Cell *queue = (Cell*)malloc(rows * cols * sizeof(Cell));
    int qh = 0, qt = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isAt[i][j] && deg[i][j] < 4) {
                queue[qt++] = (Cell){i, j};
            }
        }
    }

    unsigned long long total = 0;

    // Procesar removiendo y actualizando grados de vecinos
    while (qh < qt) {
        Cell cur = queue[qh++];
        int r = cur.r, c = cur.c;
        if (!isAt[r][c] || removed[r][c]) continue; // puede haberse retirado antes
        removed[r][c] = 1;
        isAt[r][c] = 0;      // ya no es '@'
        grid[r][c] = '.';    // opcional, por coherencia
        total++;

        // Actualizar vecinos
        for (int d = 0; d < 8; d++) {
            int ni = r + dx[d], nj = c + dy[d];
            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                if (isAt[ni][nj] && !removed[ni][nj]) {
                    if (deg[ni][nj] > 0) deg[ni][nj]--; // se retiró uno de sus vecinos
                    if (deg[ni][nj] < 4) {
                        queue[qt++] = (Cell){ni, nj};
                    }
                }
            }
        }
    }

    free(queue);
    printf("%llu\n", total);
    return 0;
}
