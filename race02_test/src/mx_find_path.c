#include "way_home.h"
#include <stdlib.h>
#include <stddef.h>

t_point *mx_next_point(t_maze *maze, t_point *point) {
    t_point *result = NULL;
    int x = point->x;
    int y = point->y;

    if (y > 0 && maze->maze[y - 1][x] != '#') {
        result = mx_create_point(x, y - 1);
    }
    else if (x < maze->width - 1 && maze->maze[y][x + 1] != '#') {
        result = mx_create_point(x + 1, y);
    }
    else if (y < maze->height - 1 && maze->maze[y + 1][x] != '#') {
        result = mx_create_point(x, y + 1);
    }
    else if (x > 0 && maze->maze[y][x - 1] != '#') {
        result = mx_create_point(x - 1, y);
    }

    return result;
}

t_point *mx_create_point(int x, int y) {
    t_point *point = (t_point *)malloc(sizeof(t_point));
    point->x = x;
    point->y = y;
    return point;
}



t_point **mx_find_path(t_maze *maze, t_point *start, t_point *end) {
    if (maze == NULL || start == NULL || end == NULL) {
        mx_print_error("Error: invalid input.\n");
        return NULL;
    }

    t_point **path = (t_point **)malloc(sizeof(t_point *) * (maze->width * maze->height + 1));

    if (path == NULL) {
        mx_print_error("Error: memory allocation failed.\n");
        return NULL;
    }

    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (maze->maze[i][j] == 0) {
                maze->maze[i][j] = -1;
            }
        }
    }

    int distance = 0;
    t_point *current = start;
    path[distance] = current;

    while (current->x != end->x || current->y != end->y) {
        distance++;

        if (distance >= maze->width * maze->height) {
            mx_print_error("Error: path not found.\n");
            free(path);
            return NULL;
        }

        t_point *next = mx_next_point(maze, current);

        if (next == NULL) {
            distance--;
            current = path[distance];
            continue;
        }

        path[distance] = next;
        current = next;
    }

    path[distance + 1] = NULL;
    return path;
}

