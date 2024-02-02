// program to demonstrate fork()

#include <stdio.h>
#include <unistd.h>

int main()
{
    int p1;
    int i = 0, y = 0;
    else if (p1 == 0) // child process
    {
        for (i = 0; i < 5; i++)
        {
            sleep(i);
            y = y + 1;
            printf("This is child.Process id=%d,parent process id=%d,y=%d\n", getpid(), getppid(), y);
        }
    }
    else // fork failed
    {
        printf("fork creation failed!!!\n");
    }
}