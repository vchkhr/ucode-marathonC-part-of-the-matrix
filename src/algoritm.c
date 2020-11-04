#include "part_of_the_matrix.h"

void algoritm(char *argv[]) {
    t_operation operation;
    enum e_error error = -1;
    bool first_n1 = true;
    bool first_n2 = true;
    bool once = true;

    error = mx_check_operation(argv[2], &operation);

    if (error == INCORRECT_OPERATION) {
        mx_printerr("Invalid operation: ");
        mx_printerr(argv[2]);
        mx_printerr("\n");
        exit(0);
    }

    char *num1_char = mx_qatoi(argv[1]);

    if (!num1_char)
        error = INCORRECT_OPERAND;
    if (error == INCORRECT_OPERAND) {
        mx_printerr("Invalid operand: ");
        mx_printerr(argv[1]);
        mx_printerr("\n");
        exit(0);
    }
    
    char *num1_check = mx_qnum(num1_char);

    char *num2_char = mx_qatoi(argv[3]);

    if (num2_char == NULL) {
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

    char *num2_check = mx_qnum(num2_char);

    char *res_char = mx_qatoi(argv[4]);

    if (res_char == NULL)
        error = INCORRECT_RESULT;
    if (error == INCORRECT_RESULT) {
        mx_printerr("Invalid result: ");
        mx_printerr(argv[4]);
        mx_printerr("\n");
        exit(0);
    }

    char *res_check = mx_qnum(res_char);

    for (int change_num1 = 0; change_num1 <= mx_strlen(num1_char); change_num1++)
        if (num1_check[change_num1] == '1')
            num1_char[change_num1] = '0';
    
    for (int change_num2 = 0; change_num2 <= mx_strlen(num2_char); change_num2++)
        if (num2_check[change_num2] == '1')
            num2_char[change_num2] = '0';

    for (int change_res = 0; change_res <= mx_strlen(res_char); change_res++)
        if (res_check[change_res] == '1')
            res_char[change_res] = '0';

    for (int end_num1 = mx_strlen(num1_char) - 1; end_num1 > -1;) {
        for (int end_num2 = mx_strlen(num2_char) - 1; end_num2 > -1;) {
            for (int end_res = mx_strlen(res_char) - 1; end_res > -1;) {
                if (num1_char[0] == '0' && mx_strlen(num1_char) > 1 && first_n1) {
                    num1_char[0] = '1';
                    first_n1 = false;
                }
                if (num2_char[0] == '0' && mx_strlen(num2_char) > 1 && first_n2) {
                    num2_char[0] = '1';
                    first_n2 = false;
                }

            
                if (operation.f(mx_atoi(num1_char), mx_atoi(num2_char)) == mx_atoi(res_char))
                    mx_printanswer(mx_atoi(num1_char), mx_atoi(num2_char), operation.op, mx_atoi(res_char));

                if (res_char[end_res] >= '0' &&  res_char[end_res] <= '9') {
                    if (res_check[end_res] == '1')
                        res_char[end_res] = (char)((int)res_char[end_res] + 1);
                    else
                        end_res--;
                }
                else {
                    if (res_char[end_res] == ':' && once) {
                        res_char[end_res] = '0';
                        res_char[end_res - 1] = (char)((int)res_char[end_res - 1] + 1);
                        once = false;
                    }
                    else {
                        once = true;
                        end_res--;
                    }
                }
                if (num2_char[end_num2] >= '0' &&  num2_char[end_num2] <= '9') {
                    if (num2_check[end_num2] == '1')
                        num2_char[end_num2] = (char)((int)num2_char[end_num2] + 1);
                    else
                        end_num2--;
                }
                else {
                    if (num2_char[end_num2] == ':' && once) {
                        num2_char[end_num2] = '0';
                        num2_char[end_num2 - 1] = (char)((int)num2_char[end_num2 - 1] + 1);
                        once = false;
                    }
                    else {
                        once = true;
                        end_num2--;
                    }
                }
                if (num1_char[end_num1] >= '0' &&  num1_char[end_num1] <= '9') {
                    if (num1_check[end_num1] == '1')
                        num1_char[end_num1] = (char)((int)num1_char[end_num1] + 1);
                    else
                        end_num1--;
                }
                else {
                    if (num1_char[end_num1] == ':' && once) {
                        num1_char[end_num1] = '0';
                        num1_char[end_num1 - 1] = (char)((int)num1_char[end_num1 - 1] + 1);
                        once = false;
                    }
                    else {
                        once = true;
                        end_num1--;
                    }
                }
            }
        }
    }

    mx_strdel(&num1_char);
    mx_strdel(&num1_check);
    mx_strdel(&num2_char);
    mx_strdel(&num2_check);
    mx_strdel(&res_char);
    mx_strdel(&res_check);
}
