#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    int start = 0;
    int end = mx_strlen(str) - 1;

    while (mx_isspace(str[start])) {
        start++;
    }

    if (str[start] == '\0') {
        return mx_strnew(0);
    }

    while (mx_isspace(str[end])) {
        end--;
    }

    char *result = mx_strnew(end - start + 1);
    if (result == NULL) {
        return NULL;
    }

    mx_strncpy(result, &str[start], end - start + 1);
    return result;
}






