int main()
{
    char str[30];

    printf("enter a paranthesized expression\n");
    scanf("%s,str");

    if (chkbalparen(str))
        printf("Balanced\n");
    else
        printf("not balanced\n");
}

int chkbalparen(char str[])
{
    STACK s;
    initStack(&s);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] = '[' || str[i] == '{')
        {
            push(&s, str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (isEmpty(&s))
                return 0;

            switch (str[i])
            {
            case ')':
                if (pop(&s) != '(')
                    return 0;
                break;
            case ']':
                if (pop(&s) != '[')
                    return 0;
                break;
            case '}':
                if (pop(&s) != '{')
                    return 0;
                break;
            }
        }
    }
    return (isEmpty(&s));
}