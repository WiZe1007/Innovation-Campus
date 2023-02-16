#ifndef WAY_HOME_H
#define WAY_HOME_H

#include <stdbool.h>

typedef struct s_maze {
    int **maze;
    int width;
    int height;
} t_maze;

typedef struct s_point {
    int x;
    int y;
} t_point;

int mx_atoi(const char *str);

bool mx_isdigit(int c);

bool mx_isspace(int c);

void mx_printerr(const char *s);

char **mx_strsplit(const char *s, char c);

t_maze *mx_parse_maze(const char *file);

void mx_print_maze(t_maze *maze);

void mx_print_path(t_maze *maze, t_point **path, t_point *start, t_point *end);

void mx_print_route(t_maze *maze, t_point **path, t_point *start, t_point *end);

t_point **mx_find_path(t_maze *maze, t_point *start, t_point *end);

void mx_print_usage(void);

void mx_print_error(const char *message);

#endif

