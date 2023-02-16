#include "way_home.h"

void mx_print_error(const char *message) {
    mx_printerr("Error: ");
    mx_printerr(message);
    mx_printerr("\n");
    exit(1);
}
