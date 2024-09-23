#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL) {
        return NULL;
    }

    int str_len = mx_strlen(str);
    int rep_len = mx_strlen(replace);
    int sub_len = mx_strlen(sub);

    if (sub_len == 0) {
        return mx_strdup(str);
    }

    int substr_count = mx_count_substr(str, sub);
    int result_size = str_len + substr_count * (rep_len - sub_len);
    char *result = mx_strnew(result_size);

    if (result == NULL) {
        return NULL;
    }

    const char *temp_sub = NULL;
    const char *temp_str = str;
    char *temp_res = result;

    while ((temp_sub = mx_strstr(temp_str, sub)) != NULL) {
        int delta = temp_sub - temp_str;
        mx_strncpy(temp_res, temp_str, delta);
        temp_res += delta;
        mx_strcpy(temp_res, replace);
        temp_res += rep_len;
        temp_str += delta + sub_len;
    }

    mx_strcpy(temp_res, temp_str);
    return result;
}







