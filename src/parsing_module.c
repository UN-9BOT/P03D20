#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_stack Stack;

struct s_stack {
    char *valueC;
    double valueD;
    int isLexem;
    int isDigit;
    int isBin;

    struct s_stack* last;
};

void parser(char *inArr);
int isDigit(char ch);
Stack *initStack();

    
int main(void) {
    char inArr[100];

    scanf("%s", inArr);
    parser(inArr);
    return (0);
}

void parser(char *inArr) {
    Stack* sp = initStack();
    Stack* qu[100];
    int cqu = 0;

    
    
    for (int i = 0; inArr[i] != '\0'; i++) {
        if (inArr[i] == 's' && inArr[i+1] == 'i' && inArr[i+2] == 'n') {
            i += 2;
            printf("sin\n");
            
        } else if (inArr[i] == 's' && inArr[i+1] == 'q' && inArr[i+2] == 'r' && inArr[i+3] == 't') {
            i += 3;
            printf("sqrt\n");
        } else if (inArr[i] == 'c' && inArr[i+1] == 'o' && inArr[i+2] == 's') {
            i += 2;
            printf("cos\n");
        } else if (inArr[i] == 'c' && inArr[i+1] == 't' && inArr[i+2] == 'g') {
            i += 2;
            printf("ctg\n");
        } else if (inArr[i] == 't' && inArr[i+1] == 'a' && inArr[i+2] == 'n') {
            i += 2;
            printf("tan\n");
        } else if (inArr[i] == 'l' && inArr[i+1] == 'n') {
            i += 1;
            printf("ln\n");
        } else if (inArr[i] == '+') {
            printf("%c\n", inArr[i]);
        } else if (inArr[i] == '-') {
            printf("%c\n", inArr[i]);
        } else if (inArr[i] == '*') {
            printf("%c\n", inArr[i]);
        } else if (inArr[i] == '(') {
            printf("%c\n", inArr[i]);
        } else if (inArr[i] == ')') {
            printf("%c\n", inArr[i]);
        } else if (isDigit(inArr[i])) {
            double num;
            sscanf(&inArr[i], "%lf", &num);
            printf("%lf\n", num);
            while (isDigit(inArr[i])) {
                i++;
            }
            i--;



        } else if (inArr[i] == 'x') {
            printf("x\n");
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
    st->valueC = NULL;
    st->valueD = 0;
    st->isLexem = 0;
    st->isDigit = 0;
    st->isBin = 0;

    st->last = NULL;
    return (st);
}

void push(Stack* last, char* valueC, double valueD, int isLexem, int isDigit, int isBin) {
    Stack* st = malloc(sizeof(Stack));
    st->valueC = NULL;
    st->valueD = 0;
    st->isLexem = 0;
    st->isDigit = 0;
    st->isBin = 0;

    st->last = last->last;

}

void pop(Stack* last, char * value) {
    Stack* st = last;
}







/* Stack *pushStack(Stack st, Stack elem) { */

    
