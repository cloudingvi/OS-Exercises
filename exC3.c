#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int n = 4; // max number of piped commands


int main () {

    while(1) {

        printf("shelly> ");

        // parsing input
        char commandLine [1024];
        fgets(commandLine, sizeof(commandLine), stdin);
        commandLine[strcspn(commandLine, "\n")] = '\0'; // removes trailing newline
        if (strcmp(commandLine, "exit") == 0) break;

        // dividing input into command blocks
        char * parsedLine = strtok(commandLine, "|");
        char * commands[n];
        int i = 0; int blocks = 0;
        while(parsedLine != NULL) {
            while(* parsedLine == ' ' || * parsedLine == '\t') parsedLine++; // trim leading spaces
            commands[i++] = parsedLine;
            blocks++;
            parsedLine = strtok(NULL, "|");
        }

        // creations of pipes
        int fd[blocks-1][2];
        for(int i = 0; i < blocks -1; i++) {
            pipe(fd[i]);
        }

        // creating a child for each block
        for (int i = 0; i < blocks; i++) {
            //printf("I parsed the command block %s\n", commands[i]);

            pid_t pid = fork();
            if (pid < 0) perror("forkn't");
            if (pid == 0) {
                // dividing the command block into instructions
                char * parsedCommands = strtok(commands[i], " ");
                char * command[n];
                int j = 0;
                while(parsedCommands != NULL) {
                    command[j++] = parsedCommands;
                    parsedCommands = strtok(NULL, " ");
                }
                command[j] = NULL;

                if (command[0] == NULL) exit(0); // if empty command, continue

                //executing the command block
                if (i > 0) dup2(fd[i-1][0], STDIN_FILENO); // replacing input to pipe if not first block
                if (i < blocks -1) dup2(fd[i][1], STDOUT_FILENO); // replacing output to pipe if not last block
                
                for (int k = 0; k < blocks - 1; k++) {
                    close(fd[k][0]);
                    close(fd[k][1]);
                }
                
                execvp(command[0], command);
                perror("execn't");
                exit(1);
            }
            else {
                if (i > 0) close(fd[i-1][0]);
                if (i < blocks - 1) close(fd[i][1]);
            }
        }

        for (int i = 0; i < blocks; i++) {
            wait(NULL);
        }

    }

    return 0;
}