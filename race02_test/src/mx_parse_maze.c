#include "way_home.h"

t_maze *mx_parse_maze(const char *file) {
    // Открываем файл для чтения.
    int fd = open(file, O_RDONLY);
    if (fd < 0) {
        mx_print_error("error: cannot open file");
        return NULL;
    }

    // Считываем размеры лабиринта.
    char buf[10];
    int bytes_read = read(fd, buf, 10);
    if (bytes_read <= 0) {
        mx_print_error("error: invalid file format");
        return NULL;
    }

    int width = 0, height = 0;
    int num_digits = 0;
    for (int i = 0; i < bytes_read; i++) {
        if (mx_isdigit(buf[i])) {
            num_digits++;
            if (num_digits == 1) {
                width = buf[i] - '0';
            } else if (num_digits == 2) {
                width = width * 10 + (buf[i] - '0');
            } else if (num_digits == 3) {
                height = buf[i] - '0';
            } else if (num_digits == 4) {
                height = height * 10 + (buf[i] - '0');
            }
        }
    }

    // Создаем структуру t_maze и инициализируем ее.
    t_maze *maze = (t_maze *) malloc(sizeof(t_maze));
    maze->width = width;
    maze->height = height;
    maze->maze = (int **) malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        maze->maze[i] = (int *) malloc(width * sizeof(int));
    }

    // Считываем лабиринт.
    int row = 0, col = 0;
    while (1) {
        int c = 0;
        bytes_read = read(fd, &c, 1);
        if (bytes_read <= 0) {
            break;
        }
        if (mx_isspace(c)) {
            continue;
        }
        if (!mx_isdigit(c)) {
            mx_print_error("error: invalid file format");
            return NULL;
        }
        maze->maze[row][col] = c - '0';
        col++;
        if (col == width) {
            col = 0;
            row++;
            if (row == height) {
                break;
            }
        }
    }

    // Закрываем файл.
    close(fd);

    return maze;
}
