#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_stack Stack;

struct s_stack {
    char valueC;
    double valueD;
    char wtf;
    int isBin;

    struct s_stack* last;
};

void parser(char *inArr, double x);
int isDigit(char ch);
Stack *initStack();
void push(Stack* last, char wtf, char valueC, double valueD, int isBin);
void pop(Stack* last, char* wtf, char* valueC, double* valueD, int* isBin);

    
int main(void) {
    char inArr[100];

    scanf("%s", inArr);
    parser(inArr, 10);
    return (0);
}

void parser(char *inArr, double x) {
    Stack* sp = initStack();
    /* Stack* qu[100]; */
    /* int cqu = 0; */

    for (int i = 0; inArr[i] != '\0'; i++) {
        if (inArr[i] == 's' && inArr[i+1] == 'i' && inArr[i+2] == 'n') {
            i += 2;
            printf("sin\n");
            push(sp, 'l', 's', 0, 1);
        } else if (inArr[i] == 's' && inArr[i+1] == 'q' && inArr[i+2] == 'r' && inArr[i+3] == 't') {
            i += 3;
            printf("sqrt\n");
            push(sp, 'l', 'q', 0, 1);
        } else if (inArr[i] == 'c' && inArr[i+1] == 'o' && inArr[i+2] == 's') {
            i += 2;
            printf("cos\n");
            push(sp, 'l', 'c', 0, 1);
        } else if (inArr[i] == 'c' && inArr[i+1] == 't' && inArr[i+2] == 'g') {
            i += 2;
            printf("ctg\n");
            push(sp, 'l', 't', 0, 1);
        } else if (inArr[i] == 't' && inArr[i+1] == 'a' && inArr[i+2] == 'n') {
            i += 2;
            printf("tan\n");
            push(sp, 'l', 'a', 0, 1);
        } else if (inArr[i] == 'l' && inArr[i+1] == 'n') {
            i += 1;
            printf("ln\n");
            push(sp, 'l', 'l', 0, 1);
        } else if (inArr[i] == '+') {
            printf("%c\n", inArr[i]);
            push(sp, 'o', '+', 0, 2);
        } else if (inArr[i] == '-') {
            printf("%c\n", inArr[i]);
            push(sp, 'o', '-', 0, 2);
        } else if (inArr[i] == '*') {
            printf("%c\n", inArr[i]);
            push(sp, 'o', '*', 0, 0);
        } else if (inArr[i] == '(') {
            printf("%c\n", inArr[i]);
            push(sp, 'b', '(', 0, 0);
        } else if (inArr[i] == ')') {
            printf("%c\n", inArr[i]);
            push(sp, 'b', ')', 0, 0);
        } else if (isDigit(inArr[i])) {
            double num;
            sscanf(&inArr[i], "%lf", &num);
            printf("%lf\n", num);
            push(sp, 'd', ' ', num, 0);
            while (isDigit(inArr[i])) {
                i++;
            }
            i--;
        } else if (inArr[i] == 'x') {
            printf("x\n");
            push(sp, 'd', ' ', x, 0);
        }
    }
    char wtf;
    char valueC;
    double valueD;
    int isBin;
    pop(sp, &wtf, &valueC, &valueD, &isBin);
    printf("%c %c %lf %d", wtf, valueC, valueD, isBin);
}

int isDigit(char ch) {
    int res = 0;
    if (ch >= 48 && ch <= 57 ) {
        res = 1;
    }
    return res;
}

Stack *initStack() {
    Stack* st = malloc(sizeof(Stack));
    st->valueC = ' ';
    st->valueD = 0;
    st->wtf = ' ';
    st->isBin = 0;

    st->last = NULL;
    return (st);
}

void push(Stack* last, char wtf, char valueC, double valueD, int isBin) {
    Stack* st = malloc(sizeof(Stack));
    st->valueC = valueC;
    st->valueD = valueD;
    st->wtf = wtf;
    st->isBin = isBin;

    *last = *st;
}

void pop(Stack* last, char* wtf, char* valueC, double* valueD, int* isBin) {
    *wtf = last->wtf;
    *valueC = last->valueC;
    *valueD = last->valueD;
    *isBin = last->isBin;
    last = last->last;
}

