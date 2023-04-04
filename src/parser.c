#include <stdio.h>
#include <stdlib.h>

char* getStr(int *is_error, int *);
void parseStr(char **arr, int);

int main(void) {
    int is_error = 0;
    int counterChar = 0;
    char* str = getStr(&is_error, &counterChar);
    if (!is_error) {
        char *arr = calloc(1, sizeof(char));
        parseStr(&arr, counterChar);
    }

}

char* getStr(int *is_error, int *counterChar) {
    char *str = calloc(1, sizeof(char));
    char c;
    if (!str) { 
        while(!is_error || (c = getchar()) != '\n') {
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

void parseStr(char **arr, int counterChar) {
    for (int i = 0; i < counterChar; i++) {
        if ((*arr)[i] == 's' && (*arr)[i+1] == 'i' && (*arr)[i+2] == 'n') {
            i += 2;
            printf("sin\n");
        } else if ((*arr)[i] == 's' && (*arr)[i+1] == 'q' && (*arr)[i+2] == 'r' && (*arr)[i+3] == 't') {
            i += 3;
            printf("sqrt\n");
        } else if ((*arr)[i] == 'c' && (*arr)[i+1] == 'o' && (*arr)[i+2] == 's') {
            i += 2;
            printf("cos\n");
        } else if ((*arr)[i] == 'c' && (*arr)[i+1] == 't' && (*arr)[i+2] == 'g') {
            i += 2;
            printf("ctg\n");
        } else if ((*arr)[i] == 't' && (*arr)[i+1] == 'a' && (*arr)[i+2] == 'n') {
            i += 2;
            printf("tan\n");
        } else if ((*arr)[i] == 'l' && (*arr)[i+1] == 'n') {
            i += 1;
            printf("ln\n");
        }

    }
}
