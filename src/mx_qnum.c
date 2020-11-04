#include "part_of_the_matrix.h"

char *mx_qnum(char *agrument) {
    char *qnum1 = mx_qatoi(agrument);
    if (!qnum1)
        return NULL;
    
    char *indexes = mx_strnew(mx_strlen(qnum1));

    for (int i = 0; i < mx_strlen(qnum1); i++)
        indexes[i] = mx_isquestion(qnum1[i]) ? '1' : '0';

    mx_strdel(&qnum1);

    return indexes;
}
