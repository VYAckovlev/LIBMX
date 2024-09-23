#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    char *temp = mx_strnew(mx_strlen(str));
    char *result = NULL;
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (!mx_isspace(str[i])) {
            temp[j++] = str[i];
        }
        if (!mx_isspace(str[i]) && mx_isspace(str[i + 1])) {
            temp[j++] = ' ';
        }
        i++;
    }
    result = mx_strtrim(temp);
    mx_strdel(&temp);
    return result;
}





