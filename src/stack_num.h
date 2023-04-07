#ifndef SN
#define SN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack_n t_stack_n;

struct Stack_n {
    double num;
    t_stack_n* prev;

};

t_stack_n* initSt_n();
t_stack_n* pushSt_n(t_stack_n* st, double num);
t_stack_n* popSt_n(t_stack_n* st, double *num);
void destroySt_n(t_stack_n* st);
#endif
