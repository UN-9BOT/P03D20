#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack_i t_stack_i;

struct Stack_i {
    int wtf;
    char lexem[5];
    int prior;
    t_stack_i* prev;

};

t_stack_i* initSt_i();
t_stack_i* pushSt_i(t_stack_i* st, int wtf, char *lexem, int prior);
t_stack_i* popSt_i(t_stack_i* st, int *wtf, char lexem[5]);
void destroySt_i(t_stack_i* st);
