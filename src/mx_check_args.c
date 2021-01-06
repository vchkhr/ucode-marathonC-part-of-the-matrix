#include "part_of_the_matrix.h"

void mx_check_args(char *argv[], char *operand1, char *operation,
                   char *operand2, char *result, int operand1_length,
                   int operation_length, int operand2_length,
                   int result_length) {

    if (operand1_length <= 0) {
        mx_error_invalid_operand(argv[1]);
    }
    if (operation_length != 1) {
        mx_error_invalid_operation(argv[2]);
    }
    if (operand2_length <= 0) {
        mx_error_invalid_operand(argv[3]);
    }
    if (result_length <= 0) {
        mx_error_invalid_result(argv[4]);
    }

    for (int i = 0; i < operand1_length; i++) {
        if (i == 0 && operand1[i] == '-') {
            continue;
        }
        if (operand1[i] != '?' && !mx_isdigit(operand1[i])) {
            mx_error_invalid_operand(argv[1]);
        }
    }

    if (*operation != '?' && *operation != '+' && *operation != '-' &&
        *operation != '*' && *operation != '/') {
        mx_error_invalid_operation(argv[2]);
    }

    for (int i = 0; i < operand2_length; i++) {
        if (i == 0 && operand2[i] == '-') {
            continue;
        }
        if (operand2[i] != '?' && !mx_isdigit(operand2[i])) {
            mx_error_invalid_operand(argv[3]);
        }
    }
    for (int i = 0; i < result_length; i++) {
        if (i == 0 && result[i] == '-') {
            continue;
        }
        if (result[i] != '?' && !mx_isdigit(result[i])) {
            mx_error_invalid_operand(argv[4]);
        }
    }

}
