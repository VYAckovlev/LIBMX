#include "../inc/libmx.h"

char *mx_strnew(int size) {
    if (size < 0) {
        return NULL;
    }

    char *result = (char *)malloc(size + 1);
    if (result != NULL) {
        for (int i = 0; i <= size; i++) {
            result[i] = '\0';
        }
    }

    return result;
}








