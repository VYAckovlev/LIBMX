#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {
    if (s1 == NULL) {
        return NULL;
    }

    int new_size = mx_strlen(s1);
    char *result = mx_strnew(new_size);
    
    if (result == NULL) {
        return NULL;
    }

    mx_strcpy(result, s1);
    return result;
}








