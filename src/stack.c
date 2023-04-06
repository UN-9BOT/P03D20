#include "stack.h"

/**
 * @brief init stack with void params
 *
 * @warning wtf = -1 -- that mean it is first elem and not use this elem in prog
 *
 * 
 * @return first elem in stack
 */
t_stack* initSt() {
    t_stack* st = calloc(1, sizeof(t_stack));
    st->wtf = 666;
    st->num = 0.0;
    st->lexem[0] = ' ';
    st->prev = NULL;
    return (st);
}

/**
 * @brief add new elem on top stack
 *
 * @param st - latest elem in stack
 * @param wtf - what is it
 * @param num 
 * @param lexem
 *
 * @return elem on top stack 
 */
t_stack* pushSt(t_stack* st, int wtf, double num, char *lexem) {
    t_stack* new_st = calloc(1, sizeof(t_stack));
    strcpy(new_st->lexem, lexem);
    new_st->num = num;
    new_st->wtf = wtf;
    new_st->prev = st;

    return (new_st);
}

/**
 * @brief pop last elem on top stack
 * @warning memory is freed from under the elem we take away
 *
 * @param st
 * @param wtf
 * @param num
 * @param lexem[5]
 *
 * @return elem under pop elem
 */
t_stack* popSt(t_stack* st, int *wtf, double *num, char lexem[5]) {
    strcpy(lexem, st->lexem);
    *num = st->num;
    *wtf = st->wtf ;
    t_stack* temp = st->prev;
    free(st);
    return(temp);
}

/**
 * @brief destroy and free all memory 
 * @warning this func need for test_modules
 *
 * @param st
 */
void destroySt(t_stack* st) {
    while (st) {
        t_stack* temp = st->prev;
        free(st);
        st = temp;
    }
    /* free(st); */
}
