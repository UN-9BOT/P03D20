#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define TRIG 1
#define NUMB 2
#define OPER 3
#define BRAC 4
#define X 5

char* getStr(int *is_error, int *);
t_stack* parseStr(char **arr, t_stack *st, int);
int isDigit(char ch);

int main(void) {
    int is_error = 0;
    int counterChar = 0;
    char* str = getStr(&is_error, &counterChar);
    if (!is_error) {
        t_stack *st = initSt();
        st = parseStr(&str, st, counterChar);
        printf("after parser %d and prev %d\n", st->wtf, st->prev->wtf);
        while (st->wtf != 666) {

            int wtf;
            double num;
            char lexem[5];
            st = popSt(st, &wtf, &num, lexem);
            printf("pop res - wtf: %d num: %lf lexem: %s\n", wtf, num, lexem);
        }
        destroySt(st);
        free(str);
    }
    return (0);
}

/**
 * @brief 
 *
 * @param is_error 
 * @param counterChar
 *
 * @return string in arr
 */
char* getStr(int *is_error, int *counterChar) {
    char *str = calloc(1, sizeof(char));
    char c;
    if (str != NULL) { 
        while(!*is_error && (c = getchar()) != '\n') {
            str[*counterChar] = c;
            str = realloc(str, sizeof(char) * (*counterChar+2));
            if (!str) {
                *is_error = 1;
            }
            (*counterChar)++;
        }
    } else {
        *is_error = 1;
    }

    return (str);
}

/**
 * @brief parsing array and push all lexem in stack
 *
 * @param arr - array 
 * @param st - stack
 * @param counterChar - counter all char in array
 */
t_stack* parseStr(char **arr, t_stack *st, int counterChar) {
    for (int i = 0; i < counterChar; i++) {
        if ((*arr)[i] == 's' && (*arr)[i+1] == 'i' && (*arr)[i+2] == 'n') {
            i += 2;
            printf("sin\n");
            st = pushSt(st, TRIG, -1, "sin");
        } else if ((*arr)[i] == 's' && (*arr)[i+1] == 'q' && (*arr)[i+2] == 'r' && (*arr)[i+3] == 't') {
            i += 3;
            printf("sqrt\n");
            st = pushSt(st, TRIG, -1, "sqrt");
        } else if ((*arr)[i] == 'c' && (*arr)[i+1] == 'o' && (*arr)[i+2] == 's') {
            i += 2;
            printf("cos\n");
            st = pushSt(st, TRIG, -1, "cos");
        } else if ((*arr)[i] == 'c' && (*arr)[i+1] == 't' && (*arr)[i+2] == 'g') {
            i += 2;
            printf("ctg\n");
            st = pushSt(st, TRIG, -1, "ctg");
        } else if ((*arr)[i] == 't' && (*arr)[i+1] == 'a' && (*arr)[i+2] == 'n') {
            i += 2;
            printf("tan\n");
            st = pushSt(st, TRIG, -1, "tan");
        } else if ((*arr)[i] == 'l' && (*arr)[i+1] == 'n') {
            i += 1;
            printf("ln\n");
            st = pushSt(st, TRIG, -1, "ln");
        } else if ((*arr)[i] == '+') {
            printf("+\n");
            st = pushSt(st, OPER, -1, "+");
        } else if ((*arr)[i] == '-') {
            printf("-\n");
            st = pushSt(st, OPER, -1, "-");
        } else if ((*arr)[i] == '*') {
            printf("*\n");
            st = pushSt(st, OPER, -1, "*");
        } else if ((*arr)[i] == '(') {
            printf("(\n");
            st = pushSt(st, BRAC, -1, "(");
        } else if ((*arr)[i] == ')') {
            printf(")\n");
            st = pushSt(st, BRAC, -1, ")");
        } else if (isDigit((*arr)[i])) {
            double num;
            sscanf(&(*arr)[i], "%lf", &num);
            printf("%lf\n", num);
            st = pushSt(st, NUMB, num, " ");
            while (isDigit((*arr)[i])) {
                i++;
            }
            /* i--; */
        } else if ((*arr)[i] == 'x') {
            printf("x\n");
            st = pushSt(st, X, -1, " ");
        }
    }
    return (st);
}

int isDigit(char ch) {
    int res = 0;
    if (ch >= 48 && ch <= 57 ) {
        res = 1;
    }
    return res;
}
