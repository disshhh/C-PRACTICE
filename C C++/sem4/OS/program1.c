#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// Add this line

int main()
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        perror("Fork failed"); // Use perror to print error message
        exit(1);
    }
    else if (pid == 0)
    {
        printf("child process\n");
        printf("id of parent=%d, id of child=%d\n", getppid(), getpid());
    }
    else
    {
        wait(NULL);
        printf("parent process\n");
        printf("id of parent=%d, id of child=%d\n", getpid(), pid);
    }
    return 0;
}
