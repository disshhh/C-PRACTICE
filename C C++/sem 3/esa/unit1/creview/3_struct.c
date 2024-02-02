#include <stdio.h>

typedef struct student
{
    int rollno;
    char a[20];
} STUDENT;
void display(STUDENT *p);
int main()
{
    STUDENT s1 = {1, "abc"};
    STUDENT s2 = {.a = "def", .rollno = 5};

    STUDENT s3 = s1;

    display(&s1);
    display(&s3);
    display(&s2);
}

void display(STUDENT *p)
{
    printf("%d %s", p->rollno, p->a);
}