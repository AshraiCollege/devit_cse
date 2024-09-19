//Design, Develop and Implement a Program for converting an Infix Expression to Postfix Expression.
//Program should support for both parenthesized and free parenthesized expressions with the
//operators: +, -, *, /, % (Remainder), ^ (Power) and alphanumeric operands.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100 // Maximum size for the stack and expression

// Stack structure for operators
typedef struct {
    int top;
    char items[MAX];
} Stack;

// Function to initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to push element onto stack
void push(Stack *s, char element) {
    if (s->top >= (MAX - 1)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = element;
}
// Function to pop element from stack
char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Function to check precedence of operators
int precedence(char operator) {
    switch (operator) {
        case '^':
            return 3;
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

// Function to check if the operator is left-associative
int isLeftAssociative(char operator) {
    if (operator == '^') return 0; // Right associative
    return 1; // Left associative for all others
}

// Function to check if character is operator
int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%' || symbol == '^');
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int i = 0, j = 0; // i -> infix index, j -> postfix index
    char token, topOperator;

    while (infix[i] != '\0') {
        token = infix[i];

        // If the token is an operand, add it to postfix
        if (isalnum(token)) {
            postfix[j++] = token;
        }
        // If the token is an open parenthesis, push it to the stack
        else if (token == '(') {
            push(&s, token);
        }
        // If the token is a closing parenthesis, pop until '(' is encountered
        else if (token == ')') {
            while (s.top != -1 && (topOperator = pop(&s)) != '(') {
                postfix[j++] = topOperator;
            }
        }
        // If the token is an operator
        else if (isOperator(token)) {
            while (s.top != -1 && isOperator(s.items[s.top])) {
                topOperator = s.items[s.top];
                // Pop from the stack to output until the operator has lower precedence
                // or the stack operator is '(' or it has different associativity
                if ((precedence(token) < precedence(topOperator)) ||
                    (precedence(token) == precedence(topOperator) && isLeftAssociative(token))) {
                    postfix[j++] = pop(&s);
                } else {
                    break;
                }
            }
            push(&s, token);
        }

        i++;
    }

    // Pop all remaining operators from the stack
    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
