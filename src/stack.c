#include "stack.h"

t_stack* initSt() {
    t_stack* st = calloc(1, sizeof(t_stack));
    st->lexem[0] = ' ';
    st->num = 0;
    st->wtf = -1;
    st->prev = NULL;
    return (st);
}

t_stack* pushSt(t_stack* st, int wtf, int num, char *lexem) {
    t_stack* new_st = calloc(1, sizeof(t_stack));
    strcpy(new_st->lexem, lexem);
    new_st->num = num;
    new_st->wtf = wtf;
    new_st->prev = st;

    return (new_st);
}

t_stack* popSt(t_stack* st, int *wtf, int *num, char lexem[5]) {
    strcpy(lexem, st->lexem);
    *num = st->num;
    *wtf = st->wtf ;
    t_stack* temp = st->prev;
    free(st);
    return(temp);
}

void destroySt(t_stack* st) {
    while (st->wtf != -1) {
        t_stack* temp = st->prev;
        free(st);
        st = temp;
    }
    free(st);
}
