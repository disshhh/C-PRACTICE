#include <stdio.h>
#include <ctype.h>
#define MAX 30

typedef struct stack
{
    int top;
    char arr[MAX];
} STACK;

void initstack(STACK *p);
void push(STACK *p, int ele);
int pop(STACK *p);
int isEmpty(STACK *p);
int stacktop(STACK *p);
void display(STACK *p);
void infitopostfi(char infix[30], char postfix[30]);
int precedence(char st, char ifi);

int main()
{
    char infix[30], postfix[30];

    printf("enter a valid infix exp:");
    scanf("%s", infix);

    infitopostfi(infix, postfix);

    printf("postfix expression is: %s\n", postfix);
}
void infixtopostfix(char infix[30], char postfix[30])
{
    STACK s;
    initstack(&s);
    char dummy;
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (isdigit(infix[i]))
        {
            postfix[k++] = infix[i];
        }
        else
        {
            while (!isEmpty(&s) && precedence(stacktop(&s), infix[i]))
            {
                postfix[k++] = pop(&s);
                if (infix[i] == ')')
                    dummy = pop(&s);
                else
                    push(&s, infix[i]);
            }
        }
        while (!isEmpty(&s))
            postfix[k++] = pop(&s);
        postfix[k++] = '\0';
    }
}
int percedence(char st, char in)
{
    switch (in)
    {
    case '-':
    case '+':
        if (st == '(')
            return 0;
        else
            return 1;
    case '*':
    case '/':
        if (st == '-' || st == '+' || st == '(')
            return 0;
        else
            return 1;
    case '(':
        return 0;
    case ')':
        if (st == '(')
            return 0;
        else
            return 1;
    }
}