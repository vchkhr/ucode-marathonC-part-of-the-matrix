#include "part_of_the_matrix.h"

void mx_error_invalid_operation(char* operation) {
    mx_printerr("Invalid operation: ");
    mx_printerr(operation);
    mx_printerr("\n");

    exit(-1);
}
