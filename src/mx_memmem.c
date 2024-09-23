#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (little_len == 0) {
        return (void *)big;
    }
    
    const unsigned char *haystack = (const unsigned char *)big;
    
    for (size_t i = 0; i <= big_len - little_len; i++) {
        unsigned char *substr_start = mx_memchr(haystack, *((unsigned char *)little), big_len - i);
        
        if (substr_start == NULL) {
            return NULL;
        }
        
        size_t offset = substr_start - (unsigned char *)big;
        
        if (offset > big_len - little_len) {
            return NULL;
        }
        
        if (substr_start && mx_memcmp(substr_start, little, little_len) == 0) {
            return substr_start;
        }
        
        haystack++;
    }
    
    return NULL;
}








