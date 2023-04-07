#include "stack_num.h"


/**
 * @brief init stack with void params
 *
 * @warning wtf = 666 -- that mean it is first elem and not use this elem in prog
 *
 * 
 * @return first elem in stack
 */
t_stack_n* initSt_n() {
    t_stack_n* st = calloc(1, sizeof(t_stack_n));
    st->num = 0.0;
    st->prev = NULL;
    return (st);
}

/**
 * @brief add new elem on top stack
 *
 * @param st - latest elem in stack
 * @param num 
 *
 * @return elem on top stack 
 */
t_stack_n* pushSt_n(t_stack_n* st, double num) {
    t_stack_n* new_st = calloc(1, sizeof(t_stack_n));
    new_st->num = num;
    new_st->prev = st;

    return (new_st);
}

/**
 * @brief pop last elem on top stack
 * @warning memory is freed from under the elem we take away
 *
 * @param st
 * @param num
 *
 * @return elem under pop elem
 */
t_stack_n* popSt_n(t_stack_n* st,double *num) {
    *num = st->num;
    t_stack_n* temp = st->prev;
    free(st);
    return(temp);
}

/**
 * @brief destroy and free all memory 
 * @warning this func need for test_modules
 *
 * @param st
 */
void destroySt_n(t_stack_n* st) {
    while (st) {
        t_stack_n* temp = st->prev;
        free(st);
        st = temp;
    }
    /* free(st); */
}
