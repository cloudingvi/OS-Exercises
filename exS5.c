#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

pid_t child;

struct sigaction act;

void handler (int signum) {
    kill(child, SIGTERM);
}

int main () {

    pid_t pid = fork();

    if (pid == 0) {
        while(1) {
            printf("helo\n");
            sleep(1);
        }
    }
    else {
        child = pid;
        act.sa_handler = handler;
        sigaction(SIGALRM, &act, NULL);

        alarm(5);
        wait(NULL);                                                                                                                                                                                  
    }

    return 0;
}