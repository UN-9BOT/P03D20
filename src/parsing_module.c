#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_stack Stack;

struct s_stack {
    char valueC;
    double valueD;
    char wtf;
    int isBin;
    int prior;

    struct s_stack* last;
};

void parser(char *inArr, double x);
int isDigit(char ch);
Stack *initStack();
Stack* push(Stack* last, char wtf, char valueC, double valueD, int isBin, int prior);
Stack* pop(Stack* last, char* wtf, char* valueC, double* valueD, int* isBi, int *prior);
void watch(Stack* last, char* wtf, char* valueC, double* valueD, int* isBin, int *prior);
Stack* getValue(Stack* last, double* valueD);

    
int main(void) {
    char inArr[100];

    scanf("%s", inArr);
    parser(inArr, 10);
    return (0);
}

double operB(char op, Stack* qu) {
    double res;
    double value1;
    double value2;
    qu = getValue(qu, &value1);
    qu = getValue(qu, &value2);
    switch (op) {
        case '*' : 
            res = value1 * value2; 
            break;
        case '/' :
            res = value2 / value1;
            break;
        case '-' :
            res = value2 - value1;
            break;
        case '+' :
            res = value1 + value2;
    }
    return (res);
}

double operU(char op, Stack* qu) {
    double res;
    double value;
    qu = getValue(qu, &value);
    switch (op) {
        case 's' : 
            res = sin(value);
            break;
        case 'q' :
            res = sqrt(value);
            break;
        case 'c' :
            res = cos(value);
        case 't' :
            res = (1 / tan(value));
            break;
        case 'a' :
            res = tan(value);
            break;
        case 'l' :
            res = log(value);
    }
    return (res);
}

void parser(char *inArr, double x) {
    Stack* sp = initStack();
    Stack* qu = initStack();

    for (int i = 0; inArr[i] != '\0'; i++) {
        if (inArr[i] == 's' && inArr[i+1] == 'i' && inArr[i+2] == 'n') {
            i += 2;
            printf("sin\n");
            sp = push(sp, 't', 's', 0, 1, 1);
            
        } else if (inArr[i] == 's' && inArr[i+1] == 'q' && inArr[i+2] == 'r' && inArr[i+3] == 't') {
            i += 3;
            printf("sqrt\n");
            sp = push(sp, 't', 'q', 0, 1, 1);
        } else if (inArr[i] == 'c' && inArr[i+1] == 'o' && inArr[i+2] == 's') {
            i += 2;
            printf("cos\n");
            sp = push(sp, 't', 'c', 0, 1, 1);
        } else if (inArr[i] == 'c' && inArr[i+1] == 't' && inArr[i+2] == 'g') {
            i += 2;
            printf("ctg\n");
            sp = push(sp, 't', 't', 0, 1, 1);
        } else if (inArr[i] == 't' && inArr[i+1] == 'a' && inArr[i+2] == 'n') {
            i += 2;
            printf("tan\n");
            sp = push(sp, 't', 'a', 0, 1, 1);
        } else if (inArr[i] == 'l' && inArr[i+1] == 'n') {
            i += 1;
            printf("ln\n");
            sp = push(sp, 't', 'l', 0, 1, 1);
        } else if (inArr[i] == '+') {
            printf("%c\n", inArr[i]);
            sp = push(sp, 'o', '+', 0, 2, 5);
        } else if (inArr[i] == '-') {
            printf("%c\n", inArr[i]);
            sp = push(sp, 'o', '-', 0, 2, 5);
        } else if (inArr[i] == '*') {
            char wtf, valueC;
            double valueD;
            int isBin, prior;
            double res;
            printf("%c\n", inArr[i]);
            watch(sp, &wtf, &valueC, &valueD, &isBin, &prior);
            if (prior <= 4) {
                if (prior == 1) { operU('*', qu); }
                else { operB('*', qu); }
            }
            sp = push(sp, 'o', '*', 0, 0, 4);
        } else if (inArr[i] == '/') {
            printf("%c\n", inArr[i]);
            sp = push(sp, 'o', '/', 0, 0, 4);
        } else if (inArr[i] == '(') {
            printf("%c\n", inArr[i]);
            sp = push(sp, 'b', '(', 0, 0, -1);
        } else if (inArr[i] == ')') {
            printf("%c\n", inArr[i]);
            sp = push(sp, 'b', ')', 0, 0, -1);
        } else if (isDigit(inArr[i])) {
            double num;
            sscanf(&inArr[i], "%lf", &num);
            printf("%lf\n", num);
            sp = push(sp, 'd', ' ', num, 0, -1);
            while (isDigit(inArr[i])) {
                i++;
            }
            i--;
        } else if (inArr[i] == 'x') {
            printf("x\n");
            sp = push(sp, 'd', ' ', x, 0, -1);
        }
    }
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
    st->prior = -1;

    st->last = NULL;
    return (st);
}

Stack* push(Stack* last, char wtf, char valueC, double valueD, int isBin, int prior) {
    Stack* st = malloc(sizeof(Stack));
    st->valueC = valueC;
    st->valueD = valueD;
    st->wtf = wtf;
    st->isBin = isBin;
    st->last = last;
    st->prior = prior;
    return(st);
}

Stack* pop(Stack* last, char* wtf, char* valueC, double* valueD, int* isBin, int *prior) {
    *wtf = last->wtf;
    *valueC = last->valueC;
    *valueD = last->valueD;
    *isBin = last->isBin;
    *prior = last->prior;
    return (last->last);
}

void watch(Stack* last, char* wtf, char* valueC, double* valueD, int* isBin, int* prior) {
    *wtf = last->wtf;
    *valueC = last->valueC;
    *valueD = last->valueD;
    *isBin = last->isBin;
    *prior = last->prior;
}

Stack* getValue(Stack* last, double* valueD) {
    *valueD = last->valueD;
    return (last->last);
}

