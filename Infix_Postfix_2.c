#include<stdio.h>
#define max 100
#define MAX 100
typedef struct {
    int top;
    char items[MAX];
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void infixToPostfix(char *in,char *pos)
{

}

int main()
{
    char infix[max],char postfix[max];

    printf("Enter your infix expression: ");
    scanf("%s",infix);

    infixToPostfix(infix,postfix);

    return 0;
}
