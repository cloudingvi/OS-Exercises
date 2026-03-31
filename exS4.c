#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

pid_t parent, child1, child2;

struct sigaction act;

void handler(int signum) {
    printf("received signal by process %d\n", getpid());
    sleep(3);
    kill(child1, SIGSTOP);
    sleep(3);
    kill(child1, SIGCONT);
    sleep(3);
    kill(child1, SIGINT);
    kill(child2, SIGINT);

}

int main () {

    pid_t pid1 = fork();
    if (pid1 == 0) {
        child1 = getpid();
        while(1) {
            printf("one\n");
        }
    }
    else {
        child1 = pid1;
        pid_t pid2 = fork();
        if (pid2 == 0) {
            child2 = getpid();
            while(1) {
                printf("two\n");
            }
        }
        else {
            child2 = pid2;
            parent = getpid();

            act.sa_handler = handler;
            sigaction(SIGUSR1, &act, NULL);

            wait(NULL);
            wait(NULL);
        }
    }

    return 0;
}
