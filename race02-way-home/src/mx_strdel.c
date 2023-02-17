#include "header.h"

void mx_strdel(char **str) {
    int i = 0;
    while (str[i]) {
        free(str[i]);
        str[i] = NULL;
        i++;
    }
}

