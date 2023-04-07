#include "stack_info.h"

/**
 * @brief init stack with void params
 *
 * @warning wtf = 666 -- that mean it is first elem and not use this elem in prog
 *
 * 
 * @return first elem in stack
 */
t_stack_i* initSt_i() {
    t_stack_i* st = calloc(1, sizeof(t_stack_i));
    st->wtf = 666;
    st->lexem = ' ';
    st->prev = NULL;
    st->prior = -2;
    return (st);
}

/**
 * @brief add new elem on top stack
 *
 * @param st - latest elem in stack
 * @param wtf - what is it
 * @param lexem
 * @param prior - priority for operations
 *
 * @return elem on top stack 
 */
t_stack_i* pushSt_i(t_stack_i* st, int wtf, char lexem, int prior) {
    t_stack_i* new_st = calloc(1, sizeof(t_stack_i));
    new_st->lexem = lexem;
    new_st->wtf = wtf;
    new_st->prev = st;
    new_st->prior = prior;

    return (new_st);
}

/**
 * @brief pop last elem on top stack
 * @warning memory is freed from under the elem we take away
 *
 * @param st
 * @param wtf
 * @param lexem[5]
 *
 * @return elem under pop elem
 */
t_stack_i* popSt_i(t_stack_i* st, int *wtf, char *lexem) {
    *lexem = st->lexem;
    t_stack_i* temp = st->prev;
    *wtf = st->wtf;
    free(st);
    return(temp);
}

/**
 * @brief destroy and free all memory 
 * @warning this func need for test_modules
 *
 * @param st
 */
void destroySt_i(t_stack_i* st) {
    while (st) {
        t_stack_i* temp = st->prev;
        free(st);
        st = temp;
    }
    /* free(st); */
}
