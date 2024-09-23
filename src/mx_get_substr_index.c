#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) {
        return -2;
    }
    const char *substr_ptr = mx_strstr(str, sub);
    if (substr_ptr == NULL) {
        return -1;
    }
    return (int)(substr_ptr - str);
}







