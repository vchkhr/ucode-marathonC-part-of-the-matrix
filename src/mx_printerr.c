#include "part_of_the_matrix.h"

void mx_printerr(const char *s) {
    write(2, s, mx_strlen(s));
}
