#include <stdio.h>

int main()
{
    int a = 5;
    int *ptr;
    ptr = &a;
    printf("%d \n", *ptr);
    printf("%d \n", a);
    printf("%d \n", ptr);
    printf("%d \n", &ptr);

    double k = 3.55;
    double *ptr2 = &k;
    printf("%f %f %d %d\n", k, *ptr2, &ptr2, ptr2);

    double **ptr3 = &ptr2;
    printf("%d %f %d\n", *ptr3, **ptr3, ptr3);
}