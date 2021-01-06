#include "part_of_the_matrix.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    int size = 0;
    int count_left = 0;
    int count_right = 0;

    for (; *str;) {
        size++;
        str++;
    }

    str -= size;

    for (; *str && mx_isspace(*str); count_left++) {
        str++;
    }

    str -= count_left;
    
    for (int i = size - 1; i >= count_left; i--) {
        if (!mx_isspace(str[i])) {
            break;
        }
        
        count_right++;
    }
    
    char *array = mx_strnew(size - count_left - count_right);
    
    for (int i = count_left, j = 0; i <= size - 1 - count_right; i++, j++) {
        array[j] = str[i];
    }
        
    return array;
}
