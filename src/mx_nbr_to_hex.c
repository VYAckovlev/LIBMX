#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr == 0) {
        char *result = mx_strnew(1);
        if (result == NULL) {
            return NULL;
        }
        result[0] = '0';
        return result;
    }

    int len = 0;
    unsigned long temp = nbr;
    while (temp != 0) {
        temp /= 16;
        len++;
    }

    char *result = mx_strnew(len);
    if (result == NULL) {
        return NULL;
    }

    for (int i = len - 1; i >= 0; i--) {
        int remainder = nbr % 16;
        if (remainder < 10) {
            result[i] = '0' + remainder;
        } else {
            result[i] = 'a' + (remainder - 10);
        }
        nbr /= 16;
    }

    return result;
}








