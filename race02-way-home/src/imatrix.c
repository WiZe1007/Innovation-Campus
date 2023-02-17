#include "header.h"

char **cmatrix (char *res, int *ryad, int *stovb) {
    int i;
    int s = 0;
    int r = 0;

    i = 0;
    while (res[i] != '\0') {
        if (res[i] == '\n') {
            ++r;
        }
        ++i;
    }
    s = (i - r) / r;

    char **mat = (char **)malloc(r * sizeof(char*));

    i = 0;
    while (i < r) {
        mat[i] = (char*)malloc(s * sizeof(char*));
        ++i;
    }

    i = 0;
    while (i < r) {
        int j = 0;
        while (j < s) {
            if (i == 0) {
                if (res[j] == '#') {
                    mat[i][j] = '#';
                }
                else if (res[j] == '.') {
                    mat[i][j] = '.';
                }
                else if (res[j] != ',' && res[j] != '\n') {
                    mx_printerr("map error\n");
                    exit(0);
                }
            }
            else {
                if (res[j + i * (s + 1)] == '#') {
                    mat[i][j] = '#';
                }
                else if (res[j + i * (s + 1)] == '.') {
                    mat[i][j] = '.';
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

