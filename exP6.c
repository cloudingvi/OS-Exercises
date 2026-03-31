#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main () {

    pid_t pid = fork();

    if (pid < 0) { // error forking
        printf("forkn't\n");
        return -1;
    }
    else if (pid == 0) { // child
        printf("smol id %d from %d\n", getpid(), getppid());
        return 0;
    }
    else if (pid > 0) { // parent
        printf("smoln't id %d\n", getpid());
        return 1;
    }
    else {
        printf("wtf\n");
        return -1;
    }
}