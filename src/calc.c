#include "part_of_the_matrix.h"

void calc(char *argv[]) {
    t_operation operation;
    enum e_error error = -1;

    error = mx_check_operation(argv[2], &operation);

    if (error == INCORRECT_OPERATION) {
        mx_printerr("Invalid operation: ");
        mx_printerr(argv[2]);
        mx_printerr("\n");
        exit(0);
    }

    int num1 = mx_atoi(argv[1]);
    
    if (num1 == (0))
        error = INCORRECT_OPERAND;
    if (error == INCORRECT_OPERAND) {
        mx_printerr("Invalid operand: ");
        mx_printerr(argv[1]);
        mx_printerr("\n");
        exit(0);
    }

    int num2 = mx_atoi(argv[3]);

    if (num2 == (0)) {
        if (operation.op == DIV)
            error = DIV_BY_ZERO;
        else
            error = INCORRECT_OPERAND;
    }
    
    if (error == INCORRECT_OPERAND) {
        mx_printerr("Invalid operand: ");
        mx_printerr(argv[3]);
        mx_printerr("\n");
        exit(0);
    }
    if (error == DIV_BY_ZERO) {
        exit(0);
    }

    int result = mx_atoi(argv[4]);

    if (result == (0))
        error = INCORRECT_RESULT;
    if (error == INCORRECT_RESULT) {
        mx_printerr("Invalid result: ");
        mx_printerr(argv[4]);
        mx_printerr("\n");
        exit(0);
    }

    int temp = operation.f(num1, num2);

    if (temp == result)
        mx_printanswer(num1, num2, operation.op, temp);

}
