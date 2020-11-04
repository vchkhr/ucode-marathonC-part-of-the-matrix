#include "part_of_the_matrix.h"

int main(int argc, char *argv[]) {
    if (argc != 5) {
        mx_printerr("usage: ./calc [operand1] [operation] [operand2] [result]\n");
        exit(0);
    }

    char *num1_check = mx_qnum(argv[1]);
    char *num2_check = mx_qnum(argv[3]);
    char *result_check = mx_qnum(argv[4]);
    
    if (mx_std(num1_check) && mx_std(num2_check) && mx_std(result_check))
        calc(argv);
    else
        algoritm(argv);

    mx_strdel(&num1_check);
    mx_strdel(&num2_check);
    mx_strdel(&result_check);
    
    return 0;
}
