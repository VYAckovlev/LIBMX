#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    if (count == NULL) {
        return -1;
    }
    if (arr == NULL || s == NULL) {
        *count = 0;
        return -1;
    }
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        (*count)++;
        int cmp = mx_strcmp(arr[mid], s);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    *count = 0;
    return -1;
}












