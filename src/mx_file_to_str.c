#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    if (file == NULL) {
        return NULL;
    }

    int fd = open(file, O_RDONLY);
    if (fd < 0) {
        return NULL;
    }

    int len = 0;
    char buffer;
    while (read(fd, &buffer, 1) > 0) {
        len++;
    }

    if (close(fd) < 0) {
        return NULL;
    }

    fd = open(file, O_RDONLY);
    if (fd < 0) {
        return NULL;
    }

    char *result = mx_strnew(len);
    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; read(fd, &buffer, 1) > 0; i++) {
        result[i] = buffer;
    }

    if (close(fd) < 0) {
        free(result);
        return NULL;
    }

    return result;
}












