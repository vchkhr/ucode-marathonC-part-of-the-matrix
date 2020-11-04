#include "part_of_the_matrix.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int counter = 0; 
    char *copy = dst; 
    while (*src != '\0' && counter< len) {
        *dst = *src;
        dst++;
        src++;
        counter++;
    }
    *dst = '\0';
    return copy;
}
