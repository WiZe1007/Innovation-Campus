#include "way_home.h"

void mx_print_maze(t_maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%d", maze->maze[i][j]);
        }
        printf("\n");
    }
}
