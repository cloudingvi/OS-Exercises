#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main () {
    int a = open("a.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    int b = open("b.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    int c = open("c.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    printf("a = %d, b = %d, c = %d\n", a, b, c);

    close(b);
    int d = open("d.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    printf("d = %d\n", d);

    close(a);
    close(c);
    close(b);

    return 0;
}