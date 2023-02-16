#include "way_home.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Проверяем количество переданных аргументов
    if (argc != 2) {
        mx_print_usage();
        return 1;
    }

    // Парсим лабиринт
    t_maze *maze = mx_parse_maze(argv[1]);
    if (!maze) {
        mx_print_error("error: invalid maze file");
        return 2;
    }

    // Находим начальную и конечную точки
    t_point start = {0, 0};
    t_point end = {0, 0};
    bool start_found = false;
    bool end_found = false;
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (maze->maze[i][j] == 2) {
                if (start_found) {
                    mx_print_error("error: multiple starting points found");
                    return 3;
                }
                start.x = j;
                start.y = i;
                start_found = true;
            } else if (maze->maze[i][j] == 3) {
                if (end_found) {
                    mx_print_error("error: multiple ending points found");
                    return 4;
                }
                end.x = j;
                end.y = i;
                end_found = true;
            }
        }
    }
    if (!start_found) {
        mx_print_error("error: starting point not found");
        return 5;
    }
    if (!end_found) {
        mx_print_error("error: ending point not found");
        return 6;
    }

    // Ищем путь в лабиринте
    t_point **path = mx_find_path(maze, &start, &end);
    if (!path) {
        mx_print_error("error: path not found");
        return 7;
    }

    // Выводим результаты
    mx_print_path(maze, path, &start, &end);
    mx_print_route(maze, path, &start, &end);

    // Освобождаем память
    for (int i = 0; i < maze->height; i++) {
        free(maze->maze[i]);
    }
    free(maze->maze);
    free(maze);
    for (int i = 0; path[i] != NULL; i++) {
        free(path[i]);
    }
    free(path);

    return 0;
}

