#include "part_of_the_matrix.h"

void mx_error_invalid_operand(char *operand) {
    mx_printerr("Invalid operand: ");
    mx_printerr(operand);
    mx_printerr("\n");

    exit(-1);
}
