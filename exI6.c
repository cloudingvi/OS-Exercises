#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void * function (void * args) {
    int * arr = (int *) args;
    int fd = arr[0];
    int i = arr[1];

    char buffer [1024] = {0};
    sprintf(buffer, "Thread %d\n", i);
    write(fd, buffer, strlen(buffer));
    pthread_exit(NULL);
}

int main () {

    int fd = open("threads.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) perror("filen't");

    for (int i  = 0; i < 4; i++) {
        pthread_t thread;
        int args [] = {fd, i};
        pthread_create(&thread, NULL, function, (void *) args);
        pthread_join(thread, NULL);
    }
    close(fd);

    int op = open("threads.txt", O_RDONLY, 0644);
    if (op == -1) perror("open't");
    char buffer [1024] = {0};
    read(op, buffer, sizeof(buffer));
    write(STDOUT_FILENO, buffer, strlen(buffer));
    
    return 0;
}