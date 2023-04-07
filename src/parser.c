#include "parser.h"
#include "stack_num.h"

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
            magic(TRIG, 's', -1, &st_i, &st_n, 1);
        } else if ((*arr)[i] == 's' && (*arr)[i+1] == 'q' && (*arr)[i+2] == 'r' && (*arr)[i+3] == 't') {
            i += 3;
            printf("sqrt\n");
            magic(TRIG, 'q', -1, &st_i, &st_n, 1);
        } else if ((*arr)[i] == 'c' && (*arr)[i+1] == 'o' && (*arr)[i+2] == 's') {
            i += 2;
            printf("cos\n");
            magic(TRIG, 'c', -1, &st_i, &st_n, 1);
        } else if ((*arr)[i] == 'c' && (*arr)[i+1] == 't' && (*arr)[i+2] == 'g') {
            i += 2;
            printf("ctg\n");
            magic(TRIG, 'g', -1, &st_i, &st_n, 1);
        } else if ((*arr)[i] == 't' && (*arr)[i+1] == 'a' && (*arr)[i+2] == 'n') {
            i += 2;
            printf("tan\n");
            magic(TRIG, 't', -1, &st_i, &st_n, 1);
        } else if ((*arr)[i] == 'l' && (*arr)[i+1] == 'n') {
            i += 1;
            printf("ln\n");
            magic(TRIG, 'l', -1, &st_i, &st_n, 1);
        } else if ((*arr)[i] == '+') {
            printf("+\n");
            magic(OPER, '+', -1, &st_i, &st_n, 3);
        } else if ((*arr)[i] == '-') {
            printf("-\n");
            magic(OPER, '-', -1, &st_i, &st_n, 3);
        } else if ((*arr)[i] == '*') {
            printf("*\n");
            magic(OPER, '*', -1, &st_i, &st_n, 1);
        } else if ((*arr)[i] == '/') {
            printf("/\n");
            magic(OPER, '/', -1, &st_i, &st_n, 1);
        } else if ((*arr)[i] == '(') {
            printf("(\n");
            magic(BRAC, '(', -1, &st_i, &st_n, 4);
        } else if ((*arr)[i] == ')') {
            printf(")\n");
            magic(BRAC, ')', -1, &st_i, &st_n, 4);
        } else if (isDigit((*arr)[i])) {
            double num;
            sscanf(&(*arr)[i], "%lf", &num);
            printf("%lf\n", num);
            magic(NUMB, ' ', num, &st_i, &st_n, -1);
            while (isDigit((*arr)[i])) {
                i++;
            }
        } else if ((*arr)[i] == 'x') {
            printf("x\n");
            magic(NUMB, ' ', 10, &st_i, &st_n, -1);
        }
    }
    printf("\noper in stack\n %c\n", st_i->lexem);
    char lex_pop;
    int wtf_pop;
    st_i = popSt_i(st_i, &wtf_pop, &lex_pop);
    double num1, num2;
    st_n = popSt_n(st_n, &num1);
    st_n = popSt_n(st_n, &num2);
    printf("\nlex pop %c\n", lex_pop);
    calcOper(lex_pop, num1, num2);
    destroySt_i(st_i);
    destroySt_n(st_n);
}

/**
 * @brief check char os digit
 *
 * @param ch
 *
 * @return true or false
 */
int isDigit(char ch) {
    int res = 0;
    if (ch >= 48 && ch <= 57 ) {
        res = 1;
    }
    return res;
}

/**
 * @brief check what is it and calculate different operations
 *
 * @param wtf
 * @param lex
 * @param num
 * @param st_i
 * @param st_n
 * @param prior
 */
void magic(int tf, char lex, double num, t_stack_i** st_i, t_stack_n** st_n, int prior) {
    if (wtf == TRIG) {
        *st_i = pushSt_i(*st_i, wtf, lex, prior);
    } else if (wtf == NUMB) {
        *st_n = pushSt_n(*st_n, num); 
    } else if (wtf == OPER) {
        while (prior >= (*st_i)->prior) {
            char lex_pop;
            int wtf_pop;
            *st_i = popSt_i(*st_i, &wtf_pop, &lex_pop);
            if (wtf_pop == TRIG) {
                double num1;
                *st_n = popSt_n(*st_n, &num1);
                /* calcTrig(lex_pop, num1); */
            } else {
                double num1, num2;
                *st_n = popSt_n(*st_n, &num1);
                *st_n = popSt_n(*st_n, &num2);
                calcOper(lex_pop, num1, num2);
            }
        }
    } else if (wtf == BRAC) {
        if (lex == '(') {
            *st_i = pushSt_i(*st_i, BRAC, '(', 4);
        /* } else { */
        /*     calcBrack(st_i, st_n); */
        }
    }
}

/**
 * @brief calculate for binary operations
 *
 * @param lex
 * @param num1
 * @param num2
 *
 * @return 
 */
doble calcOper(char lex, double num1, double num2){
    double res;
    printf("%lf && %lf", num1, num2);
    if (lex == '*') {
        res = num1 * num2;
    } else if (lex == '/') {
        res = num2 / num1;
    } else if (lex == '-') {
        res = num2 - num1;
    } else if (lex == '+') {
        res = num1 + num2;
    } else {
        printf("\nnot\n");
        printf("\n%c\n", lex);
    }
    printf("\nin calc: %lf\n", res);
    return (res);
}
