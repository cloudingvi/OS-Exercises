#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main () {

    int fd = open("shared.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    pid_t pid = fork();

    if (pid == 0) {
        char buffer [1024] = {0};
        sprintf(buffer, "child here, pid = %d\n", getpid());
        printf(buffer);
        write(fd, buffer, strlen(buffer));
        return 1;
    }
    
    else {
        wait(NULL);
        char buffer [1024] = {0};
        sprintf(buffer, "parent here, pid = %d\n", getpid());
        printf(buffer);
        write(fd, buffer, strlen(buffer));
        close(fd);
    }

    fd = open("shared.txt", O_RDONLY, 0644);
    char text [1024] = " ";
    read(fd, text, sizeof(text));
    close(fd);
    printf("From the shared file:\n");
    printf(text);
    
    return 0;
}