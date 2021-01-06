#include "part_of_the_matrix.h"

void mx_print_equation(char *operand1, char *operation, char *operand2,
                       char *result, int operand1_length, int operand2_length,
                       int result_length) {

    if (*operation == '?') {
        mx_print_equation(operand1, "+", operand2, result, operand1_length,
                          operand2_length, result_length);
        mx_print_equation(operand1, "-", operand2, result, operand1_length,
                          operand2_length, result_length);
        mx_print_equation(operand1, "*", operand2, result, operand1_length,
                          operand2_length, result_length);
        mx_print_equation(operand1, "/", operand2, result, operand1_length,
                          operand2_length, result_length);

        return;
    }

    bool operand1Negative = false;

    if (operand1[0] == '-') {
        operand1Negative = true;
        operand1++;
        operand1_length--;
    } 

    bool operand2Negative = false;

    if (operand2[0] == '-') {
        operand2Negative = true;
        operand2++;
        operand2_length--;
    }

    bool resultNegative = false;

    if (result[0] == '-') {
        resultNegative = true;
        result++;
        result_length--;
    }

    long long number1 = mx_atoi(operand1);
    long long number2 = mx_atoi(operand2);
    long long number3 = mx_atoi(result);

    for (long long i = 0; i < mx_pow(10, operand1_length); i++) {
        if (number1 > 0) {
            i = number1;
        }

        char *i_str = mx_itoa(i);
        int i_str_length = mx_strlen(i_str);

        bool iCorrect = true;

        for (int j = 0; j < operand1_length - i_str_length; j++) {
            if (mx_isdigit(operand1[j]) && operand1[j] != '0') {
                iCorrect = false;

                break;
            }
        }

        for (int j = operand1_length - i_str_length, i_str_i = 0;
             j < operand1_length; j++, i_str_i++) {
            if (operand1[j] != '?' && operand1[j] != i_str[i_str_i]) {
                iCorrect = false;

                break;
            }
        }

        free(i_str);
        i_str = NULL;

        if (!iCorrect) {
            continue;
        }

        for (long long j = 0; j < mx_pow(10, operand2_length); j++) {  
            if (number2 > 0) {
                j = number2;
            }

            char *j_str = mx_itoa(j);
            int j_str_length = mx_strlen(j_str);
            bool jCorrect = true;

            for (int j_i = 0; j_i < operand2_length - j_str_length; j_i++) {
                if (mx_isdigit(operand2[j_i]) && operand2[j_i] != '0') {
                    jCorrect = false;

                    break;
                }
            }

            for (int j_i = operand2_length - j_str_length, j_str_i = 0;
                 j_i < operand2_length; j_i++, j_str_i++) {
                if (operand2[j_i] != '?' && operand2[j_i] != j_str[j_str_i]) {
                    jCorrect = false;

                    break;
                }
            }

            free(j_str);
            j_str = NULL;

            if (!jCorrect) {
                continue;
            }
            
            for (long long k = 0; k < mx_pow(10, result_length); k++) {
                if (number3 > 0) {
                    k = number3;
                }

                char *k_str = mx_itoa(k);
                int k_str_length = mx_strlen(k_str);
                bool kCorrect = true;

                for (int k_i = 0; k_i < result_length - k_str_length; k_i++) {
                    if (mx_isdigit(result[k_i]) && result[k_i] != '0') {
                        kCorrect = false;

                        break;
                    }
                }

                for (int k_i = result_length - k_str_length, k_str_i = 0;
                     k_i < result_length; k_i++, k_str_i++) {
                    if (result[k_i] != '?' && result[k_i] != k_str[k_str_i]) {
                        kCorrect = false;

                        break;
                    }
                }

                free(k_str);
                k_str = NULL;

                if (!kCorrect) {
                    continue;
                }

                if (operand1Negative) {
                    i *= -1;
                }
                if (operand2Negative) {
                    j *= -1;
                }
                if (resultNegative) {
                    k *= -1;
                }

                if (*operation == '+') {
                    if (i + j == k) {
                        mx_print_ijk(i, " + ", j, k);
                    }
                }
                else if (*operation == '-') {
                    if (i - j == k) {
                        mx_print_ijk(i, " - ", j, k);
                    }
                }
                else if (*operation == '*') {
                    if (i * j == k) {
                        mx_print_ijk(i, " * ", j, k);
                    }
                }
                else if (*operation == '/') {
                    if (j != 0 && i / j == k) {
                        mx_print_ijk(i, " / ", j, k);
                    }
                }
                
                if (operand1Negative) {
                    i *= -1;
                }
                if (operand2Negative) {
                    j *= -1;
                }
                if (resultNegative) {
                    k *= -1;
                }
                if (number3 > 0) {
                    break;
                }
            }
            if (number2 > 0) {
                break;
            }
        }
        if (number1 > 0) {
            break;
        }
    }

    if (operand1Negative) {
        operand1--;
    }
    if (operand2Negative) {
        operand2--;
    }
    if (resultNegative) {
        result--;
    }
}
