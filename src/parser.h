#ifndef PS
#define PS

#include "stack_num.h"
#include "stack_info.h"
#define TRIG 1
#define NUMB 2
#define OPER 3
#define BRAC 4
#define X 5

char* getStr(int *is_error, int *);
void parseStr(char **arr, int);
void magic(int wtf, char lex, double num, t_stack_i**, t_stack_n**, int prior);
int isDigit(char ch);
void calcBrack(t_stack_i **, t_stack_n **);
double calcOper(char lex, double num1, double num2);
double calcTrig(char *lex, double num);
#endif
