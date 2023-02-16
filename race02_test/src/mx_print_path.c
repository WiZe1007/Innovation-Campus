#include "way_home.h"
#include <stdio.h>

void mx_print_path(t_maze *maze, t_path **path, t_point *start, t_point *end) {
    if (maze == NULL || path == NULL || start == NULL || end == NULL) {
        mx_print_error("Error: invalid input.\n");
        return;
    }

    for (int i = 0; path[i] != NULL; i++) {
        if (i == 0) {
            printf("Path:\n");
        }

        printf("(%d, %d)", path[i]->x, path[i]->y);

        if (i < mx_path_length(path) - 1) {
            printf(" -> ");
        }
    }

    printf("\n");
}
