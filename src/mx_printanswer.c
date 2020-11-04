#include "part_of_the_matrix.h"

void mx_printanswer(int num1, int num2, char op, int result) {
    mx_printint(num1);
    mx_printchar(' ');

    switch (op) {
        case SUB: mx_printchar('-'); break;
        case ADD: mx_printchar('+'); break;
        case MUL: mx_printchar('*'); break;
        case DIV: mx_printchar('/'); break;
    }

    mx_printchar(' ');
    mx_printint(num2);
    mx_printchar(' ');
    mx_printchar('=');
    mx_printchar(' ');
    mx_printint(result);
    mx_printchar('\n');
}
