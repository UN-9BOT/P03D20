#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

typedef struct { //Create structure stack
    int top; //index of top element
    char items[STACK_SIZE]; //create array for stack containing chars
} Stack; //Create stack

//Function to push char into stack
void push(Stack *ps, char item) {
    if (ps->top == STACK_SIZE-1) { //Check if stack is overflowed
        printf("Error: stack is overflowed\n");
        exit(1);
    } else {
        ps->top++; //Increase index of top element by one to next empty cell inside stack 
        ps->items[ps->top] = item; //Push item at the top of the stack 
    }
}

//Function to pop char from stack and return that char
char pop(Stack *ps) {
    if (ps->top == -1) { //Check if stask is underflowed
        printf("Error: stack underflow\n");
        exit(1);
        } else {
           char topElement = ps->items[ps->top]; //Save current top element in 'topElement'
           ps->top--; //Decrease top index by one
           return topElement; //Return current top element
        }
}

//Function to check which operator is returned
int isOperator(char symbol) {
    if (symbol == '+' || symbol == '*' || symbol == '/' || symbol == '-') {
        return 1;
    } else {
        return 0;
    }
}

//Function defining precedence
int precedence(char symbol) {
    if (symbol == '+' || symbol == '-') {
        return 1;
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    } else {
        return 0;
    }
}

//Function to define valid symbol
int isOperand(char symbol) {
    return ((symbol >= '0' && symbol <= '9') || (symbol >= 'A' && symbol <= 'Z'));
}

void infixToPostfix(char infix[], char postfix[]) {
    int i=0; //For infix expr
    int j=0; //for postfix expr
    char item; //current char
    Stack s; //our stack
    s.top = -1; // initialize empty stack

    push(&s, '('); //Push open bracket into stack
    strcat(infix, ")"); //Append closing bracket to infix expr

    item = infix[i]; //initialize item for first item in infix form

    while (item != '\0') { //make loop until end of expr
        if (item == '(') { //if current char is '('
            push(&s, item); //push it to the stack
        } else if (isOperand(item)) { //if current char is operand
            postfix[j] = item; //push it to the postfix arr
            j++; //go to the next position
        } else if (isOperator(item)) { //if the current char is operator
            int precedence_top = precedence(s.items[s.top]); //push precedence to the top of stack
            int precedence_item = precedence(item); //get current precedence

            while (s.top > -1 && precedence_top >= precedence_item) { //until stack is not empty and top precedence is higher or equal to current
                postfix[j] = pop(&s); //pop it from stack to postfix arr
                j++; //go to the next pos in postfix arr
                precedence_top = precedence(s.items[s.top]); //update top precedence
            }

            push(&s, item); //push current operator to the stack
                
        } else if (item == ')') { //if current char is closed bracket
            while (s.items[s.top] != '(') { //untill current top item is not opened bracket
                postfix[j] = pop(&s); //when pop all operators from stack to the opened bracket
                j++; //go to the next postfix pos
            }
            pop(&s); //pop opening bracket and discard it
        } else {
            printf("Error: invalid character in infix expression\n");
            exit(1);
        }
        i++; //go to the next infix pos
        item = infix[i]; //update current processed char
    }

    postfix[j] = '\0'; //add NULL char to the end of postfix arr to terminate

}

int main() {
    char infix[STACK_SIZE], postfix[STACK_SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix notation of this expression: %s", postfix);

    return 0;
}
