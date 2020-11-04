#include "part_of_the_matrix.h"

bool mx_std(char *indexes) {
    if (!indexes)
        return false;

    for (int i = 0; i < mx_strlen(indexes); i++)
        if (indexes[i] == '1')
            return false;

    return true;
}
