#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 50

char stack[MAX];
int top = -1;

// Push function
void push(char c) {
    if (top == MAX - 1)
        printf("\nStack Overflow!");
    else
        stack[++top] = c;
}

// Pop function
char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

// Check matching brackets
int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

// Main function
void main() {
    char expr[50], temp;
    int i, flag = 1;

    clrscr();
    printf("Enter an expression: ");
    gets(expr);

    for (i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
            push(expr[i]);
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (top == -1) {  // nothing to match
                flag = 0;
                break;
            } else {
                temp = pop();
                if (!isMatching(temp, expr[i])) {
                    flag = 0;
                    break;
                }
            }
        }
    }

    if (flag == 1 && top == -1)
        printf("\nExpression is Well Parenthesized.");
    else
        printf("\nExpression is Not Well Parenthesized.");

    getch();
}
