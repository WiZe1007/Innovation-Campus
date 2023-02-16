#include "way_home.h"

bool mx_isspace(int c) {
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f') {
        return true;
    }
    else {
        return false;
    }
}
