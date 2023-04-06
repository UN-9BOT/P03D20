#include <stdio.h>
#include <stdlib.h>
#include "stack_num.h"
#include "stack_info.h"

#define TRIG 1
#define NUMB 2
#define OPER 3
#define BRAC 4
#define X 5

char* getStr(int *is_error, int *);
void parseStr(char **arr, int);
void magic(int wtf, char *lex, double num, t_stack_i**, t_stack_n**, int prior);
int isDigit(char ch);
void calcBrack(t_stack_i **, t_stack_n **);
double calcOper(char oper, double num1, double num2);

int main(void) {
    int is_error = 0;
    int counterChar = 0;
    char* str = getStr(&is_error, &counterChar);
    if (!is_error) {
        parseStr(&str, counterChar);
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
 * @brief parsing array and magic
 *
 * @param arr - array 
 * @param st - stack
 * @param counterChar - counter all char in array
 */
void parseStr(char **arr, int counterChar) {
    t_stack_i *st_i = initSt_i();
    t_stack_n *st_n = initSt_n();
    for (int i = 0; i < counterChar; i++) {
        if ((*arr)[i] == 's' && (*arr)[i+1] == 'i' && (*arr)[i+2] == 'n') {
            i += 2;
            printf("sin\n");
            magic(TRIG, "sin", -1, &st_i, &st_n, 1);
        } else if ((*arr)[i] == 's' && (*arr)[i+1] == 'q' && (*arr)[i+2] == 'r' && (*arr)[i+3] == 't') {
            i += 3;
            printf("sqrt\n");
            magic(TRIG, "sqrt", -1, &st_i, &st_n, 1);
        } else if ((*arr)[i] == 'c' && (*arr)[i+1] == 'o' && (*arr)[i+2] == 's') {
            i += 2;
            printf("cos\n");
            magic(TRIG, "cos", -1, &st_i, &st_n, 1);
        } else if ((*arr)[i] == 'c' && (*arr)[i+1] == 't' && (*arr)[i+2] == 'g') {
            i += 2;
            printf("ctg\n");
            magic(TRIG, "ctg", -1, &st_i, &st_n, 1);
        } else if ((*arr)[i] == 't' && (*arr)[i+1] == 'a' && (*arr)[i+2] == 'n') {
            i += 2;
            printf("tan\n");
            magic(TRIG, "tan", -1, &st_i, &st_n, 1);
        } else if ((*arr)[i] == 'l' && (*arr)[i+1] == 'n') {
            i += 1;
            printf("ln\n");
            magic(TRIG, "ln", -1, &st_i, &st_n, 1);
        } else if ((*arr)[i] == '+') {
            printf("+\n");
            magic(OPER, "+", -1, &st_i, &st_n, 3);
        } else if ((*arr)[i] == '-') {
            printf("-\n");
            magic(OPER, "-", -1, &st_i, &st_n, 3);
        } else if ((*arr)[i] == '*') {
            printf("*\n");
            magic(OPER, "*", -1, &st_i, &st_n, 2);
        } else if ((*arr)[i] == '/') {
            printf("/\n");
            magic(OPER, "/", -1, &st_i, &st_n, 2);
        } else if ((*arr)[i] == '(') {
            printf("(\n");
            magic(BRAC, "(", -1, &st_i, &st_n, 4);
        } else if ((*arr)[i] == ')') {
            printf(")\n");
            magic(BRAC, ")", -1, &st_i, &st_n, 4);
        } else if (isDigit((*arr)[i])) {
            double num;
            sscanf(&(*arr)[i], "%lf", &num);
            printf("%lf\n", num);
            magic(NUMB, " ", num, &st_i, &st_n, -1);
            while (isDigit((*arr)[i])) {
                i++;
            }
        } else if ((*arr)[i] == 'x') {
            printf("x\n");
            magic(NUMB, " ", 10, &st_i, &st_n, -1);
        }
    }
    // TODO: printf("res = %lf", ?)
    destroySt_i(st_i);
    destroySt_n(st_n);
}

int isDigit(char ch) {
    int res = 0;
    if (ch >= 48 && ch <= 57 ) {
        res = 1;
    }
    return res;
}

void magic(int wtf, char *lex, double num, t_stack_i** st_i, t_stack_n** st_n, int prior) {
    switch (wtf) {
        case TRIG:
            break;
        case NUMB:
            *st_n = pushSt_n(*st_n, num);
            break;
        case OPER:
            while (prior >= (*st_i)->prior) {
                double num1, num2;
                *st_n = popSt_n(*st_n, &num1);
                *st_n = popSt_n(*st_n, &num2);
                calcOper(lex[0], num1, num2);
            }
            
            break;
        case BRAC:
            if (lex[0] == '(') {
                *st_i = pushSt_i(*st_i, BRAC, "(", 4);
            } else {
                calcBrack(st_i, st_n);
            }
            break;
    }
}

double calcOper(char oper, double num1, double num2){
    double res;

    return (res);
}
