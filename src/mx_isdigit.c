#include "part_of_the_matrix.h"

bool mx_isdigit(int c) {
    for (int number = 48; number <= 57; number++)
        if (c == number)
            return 1;

    return 0;
}
