#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main () {

    //sender
    while(1) {
        char buffer [1024];
        read(STDIN_FILENO, buffer, sizeof(buffer));
        if (strcmp(buffer, "quit") == 0) break;

        mkfifo("/tmp/myFifo", 0644);
        int fd = open("/tmp/myFifo", O_WRONLY);

        write(fd, buffer, strlen(buffer));
        memset(buffer, '\0', sizeof(buffer));
    }
    
    return 0;
}