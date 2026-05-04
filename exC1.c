#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main () {
    int fd[2];

    int pi = pipe(fd);
    if (pi == -1) {
        perror("pipen't");
        return -1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("forkn't");
        return -1;
    }
    // child
    else if (pid == 0) {
        close(fd[0]);
        char * msg = "The answer is 42\n";
        write(fd[1], msg, strlen(msg));
        close(fd[1]);
        exit(0);
    }
    // parent
    else {
        close(fd[1]);
        char buffer [1024] = " ";
        read(fd[0], buffer, sizeof(buffer));
        write(STDOUT_FILENO, buffer, sizeof(buffer));
        close(fd[0]);
        wait(NULL);
    }

    return 0;
}