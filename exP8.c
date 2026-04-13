#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <string.h> 

int main () {

    int c = 0;

    while(1) {

        char commandLine [1024];
        int colors [] = {31, 33, 32, 36, 34, 95};
        printf("\x1b[%dm" "myshell> " "\x1b[0m", colors[c++]);
        c %= 6;

        // parse input
        fgets(commandLine, sizeof(commandLine), stdin);
        commandLine[strcspn(commandLine, "\n")] = '\0'; // removes the trailing newline
        char * parsedLine = strtok(commandLine, " ");
        char * command[16] = {NULL};
        int i = 0;
        while(parsedLine != NULL) {
            command[i++] = parsedLine;
            parsedLine = strtok(NULL, " ");
        }
        
        if (command[0] == NULL) continue; // if empty command, continue
        if ((strcmp(command[0], "exit")) == 0) break; // if exit issued, quit shell

        pid_t pid = fork();
        if (pid < 0) perror("fork");
        else if (pid > 0) wait(NULL);
        else {
            execvp(command[0], command);
            perror("command");
            return 1;
        }
    }
    printf("good soup");
    return 0;
}
