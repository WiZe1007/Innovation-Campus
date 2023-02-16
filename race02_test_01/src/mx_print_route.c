#include "way_home.h"

void mx_print_route(t_maze *maze, t_point **path, t_point *start, t_point *end) {
    if (maze == NULL || path == NULL || start == NULL || end == NULL) {
        mx_print_error("Error: invalid input.\n");
        return;
    }

    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (mx_point_in_path(path, j, i)) {
                printf("*");
            } else if (maze->maze[i][j] == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }
}





