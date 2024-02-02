#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num[] = {10, 20, 30, 40, 50};
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%d----%d\n", *(i + num), i[num]);
    }
}