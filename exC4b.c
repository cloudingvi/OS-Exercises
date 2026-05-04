#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main () {

    //receiver
    while(1) {
        int fd = open("/tmp/myFifo", O_RDONLY);

        char buffer [1024];
        read(fd, buffer, sizeof(buffer));
        if (strcmp(buffer, "quit") == 0) {
            unlink("/tmp/myFifo");
            break;
        }

        write(STDOUT_FILENO, buffer, strlen(buffer));
        memset(buffer, '\0', sizeof(buffer));

    }

    return 0;
}