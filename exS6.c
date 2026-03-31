#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

struct sigaction increment;
struct sigaction print;
struct sigaction end;

int count = 0;

void incrementHandler (int signum) {
    printf("caught!\n");
    count++;
}

void printHandler (int signum) {
    printf("counter stopped at %d\n", count);
    count = 0;
}

void endHandler (int signum) {
    printf("okay bye\n");
    exit(0);
}


int main () {

    printf("helo from %d\n", getpid());

    increment.sa_handler = incrementHandler;
    sigaction(SIGUSR1, &increment, NULL);

    print.sa_handler = printHandler;
    sigaction(SIGUSR2, &print, NULL);

    end.sa_handler = endHandler;
    sigaction(SIGTERM, &end, NULL);

    while(1) {
        printf("I am alive!\n");
        sleep(3);
    }

    return 0;
}