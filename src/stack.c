#include <stdio.h>
typedef struct Stack t_stack;

struct Stack {
    int wtf;
    int num;
    char lexem[5];
    t_stack* prev;

};

t_stack* initStack();
t_stack* push(t_stack* st);
t_stack* pop(t_stack* st);


