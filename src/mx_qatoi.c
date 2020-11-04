#include "part_of_the_matrix.h"
#include <stdio.h>

char *mx_qatoi(const char *str) {
    char *newchar = mx_strnew(mx_strlen(str));
    bool none = false;

    for (int i = 0, j = 0; str[i] != '\0'; i++) {
        if (mx_isspace(str[i]))
            continue;
        else if (mx_isquestion(str[i]) || mx_isdigit(str[i])) {
            newchar[j] = str[i];
            j++;
        }
        else {
            none = true;
            break;
        }
    }

    if (none)
        return NULL;

    return mx_strdup(newchar);
}
