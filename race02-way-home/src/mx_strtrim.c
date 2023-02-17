#include "header.h"

char *mx_strtrim(const char *str) {
    int len = mx_strlen(str);
    int start = 0;
    int last = 0;
    char *result;

    if (!str)
        return NULL;
    while (mx_isspace(str[start])) {
        start++;
    }
    while (mx_isspace(str[len - last - 1])) {
        last++;
    }
    result = mx_strnew(len - start - last);
    mx_strncpy(result, str + start, len - start - last);
    return result;
}

