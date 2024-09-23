#include "../inc/libmx.h"

char *mx_itoa(int number) {
    bool is_negative = number < 0;
    int len = is_negative ? 1 : 0;
    long temp = number;
    long temp_counter = number;

    if (is_negative) {
        temp = -temp;
        temp_counter = -temp_counter;
    }

    if (number == 0) {
        len++;
    }

    while (temp_counter > 0) {
        len++;
        temp_counter /= 10;
    }

    char *result = mx_strnew(len);
    if (result == NULL) {
        return NULL;
    }

    if (is_negative) {
        result[0] = '-';
    }

    for (int i = is_negative; i < len; i++) {
        result[i] = '0' + (temp / (long)mx_pow(10, len - i - 1)) % 10;
    }

    return result;
}











