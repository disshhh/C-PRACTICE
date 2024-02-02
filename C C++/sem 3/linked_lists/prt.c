#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 30

typedef struct stack
{
    int head;
    char a[MAX];
} deck;

void objini(deck *ps);
int unfill(deck *ps);
void fill(deck *ps, char ele);
char dele(deck *ps);
char st(deck *ps);
void pifi(char oore[], char pifi[]);
int pfheadf(char st, char in);

int main()
{

    char infi[30], pd[30];
    scanf("%s", infi);
    pifi(infi, pd);
    printf("%s\n", pd);
    return 0;
}

void objini(deck *ps)
{
    ps->head = -1;
}

int unfill(deck *ps)
{
    return ps->head == -1;
}

void fill(deck *ps, char ele)
{
    ps->a[++(ps->head)] = ele;
}

char dele(deck *ps)
{
    return ps->a[ps->head--];
}

char st(deck *ps)
{
    return ps->a[ps->head];
}

void pifi(char oore[], char pifi[])
{
    deck s;
    objini(&s);
    
    int k = 0;
    for (int i = 0; oore[i] != '\0'; i++)
    {
        if (isdigit(oore[i]))
        {
            pifi[k] = oore[i];
            k++;
        }
        else
        {
            while (!unfill(&s) && pfheadf(st(&s), oore[i]))
            {
                pifi[k] = dele(&s);
                k++;
            }
            if (oore[i] == ')')
            {
                dele(&s);
            }
            else
            {
                fill(&s, oore[i]);
            }
        }
    }
    while (!unfill(&s))
    {
        pifi[k++] = dele(&s);
    }
    pifi[k] = '\0';
    return;
}

int pfheadf(char st, char in)
{
    switch (in)
    {
    case '+':
    case '-':
        if (st == '(')
            return 0;
        else
            return 1;

    case '*':
    case '/':
        if (st == '+' || st == '-' || st == '(')
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
    return 1;
}
