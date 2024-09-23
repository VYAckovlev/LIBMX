#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 == NULL && s2 == NULL) {
        return NULL;
    }
    if (s1 == NULL) {
        return mx_strdup(s2);
    }
    if (s2 == NULL) {
        return mx_strdup(s1);
    }

    int s1_len = mx_strlen(s1);
    int s2_len = mx_strlen(s2);
    char *result = mx_strnew(s1_len + s2_len);

    if (result == NULL) {
        return NULL;
    }

    mx_strcat(result, s1);
    mx_strcat(result, s2);

    return result;
}






