#ifndef PART_OF_THE_MATRIX_H
#define PART_OF_THE_MATRIX_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool mx_isdigit(char c);
bool mx_isspace(char c);
char *mx_itoa(long long number);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str); 
double mx_pow(double n, unsigned int pow);
int mx_strlen(const char *s);
long long mx_atoi(const char* str);
void mx_check_args(char *argv[], char *operand1, char *operation,
                   char *operand2, char *result, int operand1_length,
                   int operation_length, int operand2_length,
                   int result_length);
void mx_error_invalid_operand(char *operand);
void mx_error_invalid_operation(char* operation);
void mx_error_invalid_result(char* result);
void mx_print_equation(char *operand1, char *operation, char *operand2,
                       char *result, int operand1_length, int operand2_length,
                       int result_length);
void mx_print_ijk(int i, char *operation, int j, int k);
void mx_printchar(char c);
void mx_printerr(const char *s);
void mx_printint(int n);
void mx_printstr(const char *s);

#endif
