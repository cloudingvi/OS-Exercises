#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char * argv []) {

    char * filename = argv[1];
    printf("Looking for %s\n",filename);
    int fd = open(filename, O_RDONLY, 0644);
    if (fd == -1) {
        perror("nop, problems with the file\n");
        return 42;
    }
    char buffer [1024] = {0};
    read(fd, buffer, sizeof(buffer));
    write(STDOUT_FILENO, buffer, strlen(buffer));

    return 0;
}