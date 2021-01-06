#include "part_of_the_matrix.h"

void mx_error_invalid_result(char* result) {
    mx_printerr("Invalid result: ");
    mx_printerr(result);
    mx_printerr("\n");

    exit(-1);
}
