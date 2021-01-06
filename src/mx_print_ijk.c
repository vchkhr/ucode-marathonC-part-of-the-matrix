#include "part_of_the_matrix.h"

void mx_print_ijk(int i, char *operation, int j, int k) {
    mx_printint(i);
    mx_printstr(operation);
    mx_printint(j);
    mx_printstr(" = ");
    mx_printint(k);
    mx_printchar('\n');
}
