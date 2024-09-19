/*Design, Develop and Implement a Program for the following Stack Applications
a. Evaluation of Postfix expression with single digit operands and operators: +, -, *, /, %, ^
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

// Stack implementation
typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->data[++(s->top)] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    } else {
        printf("Stack Underflow\n");
        exit(1);
    }
}

int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    } else {
        printf("Stack is empty\n");
        exit(1);
    }
}

// Function to evaluate the postfix expression
int evaluatePostfix(char* expression) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        // If the character is an operand (digit), push it onto the stack
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');  // Convert char to int
        }
        // If the character is an operator, pop two operands and evaluate
        else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;

            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    result = operand1 / operand2;
                    break;
                case '%':
                    result = operand1 % operand2;
                    break;
                case '^':
                    result = pow(operand1, operand2);
                    break;
                default:
                    printf("Error: Unsupported operator %c\n", expression[i]);
                    exit(1);
            }
            push(&stack, result);
        }
    }

    // The final result will be the only element in the stack
    return pop(&stack);
}

int main() {
    char postfixExpression[MAX];

    printf("Enter a postfix expression (single digit operands): ");
    scanf("%s", postfixExpression);

    int result = evaluatePostfix(postfixExpression);
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}
