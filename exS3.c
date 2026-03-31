#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

struct sigaction act1;
struct sigaction act2;

void handler1(int signum) {
    printf("one\n");
}

void handler2(int signum) {
    printf("two\n");
}

int main () {

    act1.sa_handler = handler1;
    sigaction(SIGUSR1, &act1, NULL);

    act2.sa_handler = handler2;
    sigaction(SIGUSR2, &act2, NULL);

    while(1) {
        printf("helo\n");
        sleep(3);
    }

    return 0;
}