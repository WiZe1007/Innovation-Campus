#include "way_home.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if(argc != 6) {
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]");
    }
    char s[1];
    int f = open(argv[1], O_RDONLY);
    int u = read(f, s, sizeof(s));

    if(f < 0) {
        mx_printerr("map does not exist\n");
        exit(0);
    }
    else if(u <= 0) {
        mx_printerr("map does not exist\n");
        exit(0);
    }
}
