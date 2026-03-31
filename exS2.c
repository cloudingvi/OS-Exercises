#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int flag = 0;
time_t flagTime = 0;

struct sigaction act;

void handler(int signum) {
    if (flag == 1) {
        printf("\nok you got me, bye\n");
        exit(0);
    }
    else {
        printf("\nlol you wish. try again (fast)\n");
        flag = 1;
        flagTime = time(NULL);
    }
}

int main() {

    act.sa_handler = handler;
    sigaction(SIGINT, &act, NULL);

    while(1) {
        printf("correndo\n");
        sleep(2);

        if (flag == 1) {
            while(time(NULL) - flagTime < 3) {
                flag = 1;
            }
            flag = 0;
        }
    }
    return 0;
}