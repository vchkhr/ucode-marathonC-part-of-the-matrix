#include "part_of_the_matrix.h"

char *mx_itoa(long long number) {
    char *number_string = NULL;

    if (number == 0) {
        number_string = mx_strnew(1);
        number_string[0] = '0';

        return number_string;
    }

    int length = 0;
    long long number_copy = number;

    if (number_copy < 0) {
        length++;
        number_copy *= -1;
    }

    for (; number_copy != 0; length++) {
        number_copy /= 10;
    }

    number_string = mx_strnew(length);
    
    if (number < 0) {
        number_string[0] = '-';
        number *= -1;
    }

    number_string[length--] = '\0';

    for (; (number != 0 && length >= 0) && number_string[length] != '-';
         number /= 10) {
        number_string[length--] = (number % 10) + '0';
    }

    return number_string;
}
