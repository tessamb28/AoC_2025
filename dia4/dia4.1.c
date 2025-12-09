#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// Desplazamientos en las 8 direcciones
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s archivo.txt\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror("No se pudo abrir archivo");
        return 1;
    }

    char grid[MAX][MAX];
    int filas = 0, cols = 0;

    // Leer la cuadrícula
    while (fgets(grid[filas], MAX, f)) {
        grid[filas][strcspn(grid[filas], "\r\n")] = '\0';
        if (cols == 0) cols = strlen(grid[filas]);
        filas++;
    }
    fclose(f);

    int accesibles = 0;

    // Recorrer cada celda
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '@') {
                int vecinos = 0;
                for (int d = 0; d < 8; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < filas && nj >= 0 && nj < cols) {
                        if (grid[ni][nj] == '@') vecinos++;
                    }
                }
                if (vecinos < 4) accesibles++;
            }
        }
    }

    printf("%d\n", accesibles);
    return 0;
}
