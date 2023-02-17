#include "header.h"

char *mx_strnew(const int size) {
    char *str = malloc(size + 1);
    if (str == NULL) {
        return str;
    }
    int i = 0;
    while (i < size + 1) {
        str[i] = '\0';
        ++i;
    }
    return str;
}

