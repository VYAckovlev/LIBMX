#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (s == NULL) {
        return NULL;
    }

    int count_words = mx_count_words(s, c);
    char **result = (char **)malloc(sizeof(char *) * (count_words + 1));
    if (result == NULL) {
        return NULL;
    }

    result[count_words] = NULL;
    int j = 0;

    for (int i = 0; i < count_words; i++) {
        while (s[j] == c) {
            j++;
        }

        int start = j;
        while (s[j] != c && s[j] != '\0') {
            j++;
        }

        int word_length = j - start;
        result[i] = mx_strnew(word_length);

        if (result[i] == NULL) {
            return NULL;
        }

        mx_strncpy(result[i], s + start, word_length);
    }

    return result;
}






