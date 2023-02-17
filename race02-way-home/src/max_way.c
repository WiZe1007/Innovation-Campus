#include "header.h"

int max(int **grid, int ax, int ay, int He, int Wi, char **final) {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int d = 0;
    int maxim;
    bool stop = false;
    int flag = 1;

    grid[ay][ax] = 0;
    while (!stop || flag) {
        stop = true;
        int y = 0;
        while (y < He) {
            int x = 0;
            while (x < Wi) {
                if (grid[y][x] == d) {
                    for (int k = 0; k < 4; ++k) {
                        int iy = y + dy[k], ix = x + dx[k];
                        if (iy >= 0 && iy < He && ix >= 0 && ix < Wi && grid[iy][ix] == -2) {
                            stop = false;
                            grid[iy][ix] = d + 1;
                        }
                    }
                }
                x++;
            }
            y++;
        }
        d++;
        flag = 0;
    }
    maxim = grid[0][0];
    int i = 0;
    while (i < He) {
        int j = 0;
        while (j < Wi) {
            if (grid[i][j] > maxim) {
                maxim = grid[i][j];
            }
            j++;
        }
        i++;
    }
    int m = 0;
    while (m < He) {
        int n = 0;
        while (n < Wi) {
            if (grid[m][n] == maxim) {
                if (final[m][n] == '*') {
                    final[m][n] = 'X';
                }
                else {
                    final[m][n] = 'D';
                }
            }
            n++;
        }
        m++;
    }
    return maxim;
}

