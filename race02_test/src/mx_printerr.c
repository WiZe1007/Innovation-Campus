#include "way_home.h"

void mx_printerr(const char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    write(2, s, i);
}
