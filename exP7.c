#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void multiplicate(int p, int l, int depth) {

    if (l == 0) {
        return;
    }
    else {
        for (int i = 1; i <= p; i++) {

            pid_t pid = fork();
            
            if (pid == 0) { // if you are a child
                for (int d = 0; d < depth; d++) {
                    printf("        ");
                }
                printf("-- child %d of %d here, id %d\n", i, getppid(), getpid());
                printf("\n");
                multiplicate(p, l-1, depth + 1);
                exit(0);
            }

            else if (pid > 0) { // if you are a parent
                wait(NULL);
                continue;
            }
        }
    }
}

int main (int argc, char * argv[]) {

    int p = atoi(argv[1]);
    int l = atoi(argv[2]);

    printf("\n p = %d and l = %d\n", p, l); printf("\n");

    if ((p > 0) && (l > 0) && (l < 10) && (p > l)) {
        printf("%d -- \n", getpid());
        multiplicate(p, l, 1);
    }
    else if (p < 0 || l < 0) {
        printf("you can't use negatives\n");
    }
    else {
        printf("nop\n");
    }

    //printf("I got here and I am %d ~\n", getpid());

    return 0;
}