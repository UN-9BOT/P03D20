#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void valid(char *inArr);
int isDigit(char ch);

typedef struct s_stack Stack;
struct element {
    char * value;
    int priority;
};

struct s_stack {
    struct element* elem;
    struct s_stack* last;
};
    
int main(void) {
    char inArr[100];

    /* int i = 0; */
    scanf("%s", inArr);
    /* while(putchar(inArr[i++]) != '\0'); */
    valid(inArr);
    return (0);
}

void valid(char *inArr) {
    Stack out[100];
    Stack st[100];
    int outC = 0, stackC = 0;
    /* int countArr = 0; */
    /* int flag = 1; */
    
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

Stack *initStack(char* new) {
    Stack* st = malloc(sizeof(Stack));
    st->elem->value = new;
    st->last = NULL;
    return (st);
}

void push(Stack* last, char* new) {
    Stack* st = malloc(sizeof(Stack));
    st->value = new;
    st->last = last;
}

void pull(Stack* last, char * value) {
    Stack* st = last;
    value = last->value;
}







/* Stack *pushStack(Stack st, Stack elem) { */

    
