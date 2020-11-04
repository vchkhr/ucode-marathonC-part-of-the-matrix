#ifndef PART_OF_THE_MATRIX_H
#define PART_OF_THE_MATRIX_H

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

int mx_add(int a, int b);
int mx_sub(int a, int b);
int mx_mul(int a, int b);
int mx_div(int a, int b);

typedef struct s_operation{
    char op;
    int (*f)(int a, int b);
}              t_operation;

enum e_operation{
    SUB,
    ADD,
    MUL,
    DIV
};

enum e_error{
    INCORRECT_OPERAND,
    INCORRECT_OPERATION,
    INCORRECT_RESULT,
    DIV_BY_ZERO
};

int mx_atoi(const char *);
char *mx_qatoi(const char *);
bool mx_isdigit(int);
bool mx_isspace(char);
bool mx_isquestion(char);
void mx_printchar(char);
void mx_printint(int n);
int mx_strcmp(const char *, const char *);
int mx_strlen(const char*);
void mx_printstr(const char *);
void mx_printerr(const char *);
char *mx_strcpy(char *, const char *);
char *mx_strnew(const int);
char *mx_strdup(const char *);
char *mx_strncpy(char *dst, const char *src, int len);
void calc(char *[]);
void algoritm(char *[]); 
char *mx_qnum(char *);
bool mx_std(char *);
void mx_strdel(char **);
int mx_check_operation(char *, t_operation *);
void mx_printanswer(int, int, char, int);

#endif
