#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main () {

    int fd = open("my_file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("filen't");
        return 42;
    }

    char text [] = "Hello, file descriptors!\n";
    int wr = write(fd, text, sizeof(text));
    if (wr == -1) {
        perror("writen't");
        return 42;
    }

    int cl = close(fd);
    if (cl == -1) {
        perror("closen't");
        return 42;
    }

    int op = open("my_file.txt", O_RDONLY, 0644);
    if (op == -1) {
        perror("open't");
        return 42;
    }

    char buffer [1024] = " ";
    int rd = read(op, buffer, sizeof(buffer));
    if (rd == -1) {
        perror("readn't");
        return 42;
    }
    write(STDOUT_FILENO, buffer, sizeof(buffer));

    return 0;
}