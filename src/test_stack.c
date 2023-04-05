#include <stdio.h>
#include "stack.h"

int main(void) {
    t_stack* st = initSt();
    st = pushSt(st, 1, 100, "fd");
    int wtf;
    int num;
    char lexem[5];
    st = popSt(st, &wtf, &num, lexem);
    printf("%d %d %s", wtf, num, lexem);
    destroySt(st);
    return (0);
}
