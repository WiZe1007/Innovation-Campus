#include "way_home.h"

void mx_printstr(const char *s) {
    write(1, s, mx_strlen(s));
}

void mx_print_usage(void) {
    mx_printstr("Usage: ./maze [filename]\n");
}

