#include "part_of_the_matrix.h"

int mx_check_operation(char *op, t_operation *operation) {
    enum e_error error = -1;

    for (int i = 0; mx_isspace(*op); i++)
        op++;
    
    int end = mx_strlen(op) - 1;
    
    while (mx_isspace(op[end])) {
        end--;
    }

    char *temp = op;
    mx_strncpy(op, temp, ++end);

    if (mx_strcmp(op, "-") == 0) {
        enum e_operation oper = SUB;
        operation->op = oper;
        operation->f = mx_sub;
    }
    else if (mx_strcmp(op, "+") == 0) {
        enum e_operation oper = ADD;
        operation->op = oper;
        operation->f = mx_add;
    }
    else if (mx_strcmp(op, "*") == 0) {
        enum e_operation oper = MUL;
        operation->op = oper;
        operation->f = mx_mul;
    }
    else if (mx_strcmp(op, "/") == 0) {
        enum e_operation oper = DIV;
        operation->op = oper;
        operation->f = mx_div;
    }
    else
        error = INCORRECT_OPERATION;
    
    return error;
}
