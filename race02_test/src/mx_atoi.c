#include "way_home.h"

int mx_atoi(const char *str) {
    int result = 0;
    int sign = 1;
    while (*str != '\0') {
        if (*str == '-') {
            sign = -1;
            str++;
        }
        if (*str >= '0' && *str <= '9') {
            result = result * 10 + (*str - '0');
            str++;
        }
        else {
            break;
        }
    }
    return result * sign;
}
