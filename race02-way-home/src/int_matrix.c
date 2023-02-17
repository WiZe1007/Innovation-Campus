#include "header.h"

int **matrix (char *res, int *ryad, int *stovb) {
    int i = 0;
    int s = 0;
    int r = 0;

    while (res[i] != '\0') {
        if (res[i] == '\n') {
           ++r;
        }
        ++i;
    }
    s = (i - r) / r;

    int **mat = (int **)malloc(r * sizeof(int*));

    i = 0;
    while (i < r) {
        mat[i] = (int*)malloc(s * sizeof(int*));
        ++i;
    }

    i = 0;
    while (i < r) {
        int j = 0;
        while (j < s) {
            if (i == 0) {
                if (res[j] == '#') {
                    mat[i][j] = -1;
                }
                else if (res[j] == '.') {
                    mat[i][j] = -2;
                }
                else if (res[j] != ',' && res[j] != '\n') {
                    mx_printerr("map error\n");
                    exit(0);
                }
            }
            else {
                if (res[j + i * (s + 1)] == '#') {
                    mat[i][j] = -1;
                }
                else if (res[j + i * (s + 1)] == '.') {
                    mat[i][j] = -2;
                }
                else if (res[j + i * (s + 1)] != ',' && res[j + i * (s + 1)] != '\n') {
                    mx_printerr("map error\n");
                    exit(0);
                }
            }
            ++j;
        }
        ++i;
    }

    *stovb = s;
    *ryad = r;
    return mat;
}

