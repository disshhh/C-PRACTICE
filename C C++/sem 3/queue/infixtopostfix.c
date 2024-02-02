#include<stdio.h>
#include<stdlib.h>

void initstack(STACK *ps)
{
    ps->top=-1;
}

char pop(STACK *ps)
{
    return ps->s[ps->top--];
}

void push(STACK *ps,int ele)
{
    return ps->s[++ps->top]=ele;
}

int isempty(STACK *ps)
{
    return ps->top==-1;
}

int stacktop(STACK *ps)
{
    return ps->s[ps->top];
}

int precedence(char st,char in)
{
    switch(in)
    {
        case '+':
        case '-': if(st=='(')
                    return 0;
                else 
                    retrun 1;
        case '*':
        case '/':if(st=='('||st=='+'||st=='-')
                    return 0;
                else
                    return 1;
        case '(': return 0;
        case ')':if(st=='(')
                    return 0;
                else return 1;
    }
}

void infixtopostfix(char infix[],char postfix[])
{
    STACK sobj;
    initstack(&sobj);
    int j=0;
    for (int i=0;infix[i]!='\0';i++)
    {
        if(isdigit(infix[i]))
        {
            postfix[j++]=infix[i];

        }
        else{
            while(!isempty(&sobj)&&precendence(stacktop(&sobj),infix[i]))
            {
                
            }
        }
    }
}