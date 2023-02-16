#include "way_home.h"

char **mx_strsplit(const char *s, char c) {
    if (s == NULL) {
        return NULL;
    }
    int len = 0;
    int num_words = 0;
    while (s[len] != '\0') {
        if (s[len] != c) {
            num_words++;
            while (s[len] != c && s[len] != '\0') {
                len++;
            }
        }
        else {
            len++;
        }
    }
    char **result = (char **) malloc(sizeof(char *) * (num_words + 1));
    int i = 0;
    int start = 0;
    int end = 0;
    int word_len = 0;
    while (s[end] != '\0' && i < num_words) {
        if (s[end] != c) {
            start = end;
            while (s[end] != c && s[end] != '\0') {
                end++;
            }
            word_len = end - start;
            result[i] = (char *) malloc(sizeof(char) * (word_len + 1));
            result[i] = mx_strncpy(result[i], s + start, word_len);
            i++;
        }
        else {
            end++;
        }
    }
    result[i] = NULL;
    return result;
}

