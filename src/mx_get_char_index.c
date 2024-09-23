#include "../inc/libmx.h"

int mx_get_char_index(const char *str, char c) {
    if (str == NULL) {
        return -2;
    }
    const char *char_ptr = mx_memchr(str, c, mx_strlen(str));
    if (char_ptr == NULL) {
        return -1;
    }
    return (int)(char_ptr - str);
}







