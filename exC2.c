#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main () {

    // parent to child pipe
    int p2c[2];
    if (pipe(p2c) == -1) {
        perror("onen't");
        return -1;
    }
    // child to parent pipe
    int c2p[2];
    if (pipe(c2p) == -1) {
        perror("twon't");
        return -1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("childn't");
        return -1;
    }
    // child
    else if (pid == 0) {
        close(c2p[0]); close(p2c[1]);

        char buffer [1024] = {0};
        read(p2c[0], buffer, sizeof(buffer));

        int n = 2 * atoi(buffer);
        char * msg;
        asprintf(&msg, "%d", n);
        write(c2p[1], msg, strlen(msg));

        close(c2p[1]); close(p2c[0]);
        exit(0);
    }
    // parent
    else {
        close(c2p[1]); close(p2c[0]);

        char * msg = "30\n";
        write(p2c[1], msg, strlen(msg));

        char buffer [1024] = {0};
        read(c2p[0], buffer, sizeof(buffer));

        close(p2c[1]); close(c2p[0]);

        sprintf(buffer, "%d\n", atoi(buffer));
        write(STDOUT_FILENO, buffer, strlen(buffer));
        wait(NULL);
    }

    return 0;
}