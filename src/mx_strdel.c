#include "part_of_the_matrix.h"

void mx_strdel(char **str) {
    free(*str);
    *str = NULL;
}
