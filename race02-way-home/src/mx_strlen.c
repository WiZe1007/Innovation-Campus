#include "header.h"

int mx_strlen(const char *s) {
    const char* str = s;

    while (*str) {
        str++;
    }
    return str - s;
}

