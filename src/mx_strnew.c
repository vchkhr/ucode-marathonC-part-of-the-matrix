#include "part_of_the_matrix.h"

char *mx_strnew(const int size) {
    if (size < 1)
        return NULL;
    
    char *arr = (char *) malloc(size + 1);

    for (int i = 0; i <= size; i++)
        arr[i] = '\0';

    return arr;
}
