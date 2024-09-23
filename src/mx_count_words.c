#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL) {
        return -1;
    }
    bool in_word = false;
    int count = 0;
    while (*str != '\0') {
        if (*str == c) {
            in_word = false;
        }
        else if (!in_word) {
            in_word = true;
            count++;
        }
        str++;
    }
    return count;
}













