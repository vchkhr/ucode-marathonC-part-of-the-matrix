#include "part_of_the_matrix.h"

void mx_printerr(const char *s) {
    for (; *s; ) {
        write(STDERR_FILENO, s++, 1);
    }
}
