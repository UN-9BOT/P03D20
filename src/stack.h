#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack t_stack;

struct Stack {
    int wtf;
    int num;
    char lexem[5];
    t_stack* prev;

};

t_stack* initSt();
t_stack* pushSt(t_stack* st, int wtf, int num, char *lexem);
t_stack* popSt(t_stack* st, int *wtf, int *num, char lexem[5]);
void destroySt(t_stack* st);
