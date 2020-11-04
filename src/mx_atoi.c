#include "part_of_the_matrix.h"

int mx_atoi(const char *str) {
    bool none = false;
    int num = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (mx_isspace(str[i]))
            continue;
        else if (mx_isdigit(str[i]))
            num = num * 10 + (int)str[i] - 48;
        else if (!mx_isdigit(str[i])) {
            none = true;
            break;
        }
        
    }

    if (none)
        return (0);

    return num;
}
