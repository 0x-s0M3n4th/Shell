#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    // Flush after every printf
    setbuf(stdout, NULL);

    do {
        // Printing the classic dollar sign for prompt
        printf("$ ");

        // Waiting for user input
        char command[1024];
        fgets(command, sizeof(command), stdin);
        // Removing newlines from the user provided command
        command[strcspn(command, "\n")] = '\0';


        // on writting exit -> the shell will exit it's execution
        if (strcmp(command, "exit") == 0) {
      exit(EXIT_SUCCESS);
    }
        // for echo we need to print the next occurances of words after the command echo itself:
        if (strncmp(command, "echo ", 5) == 0) {
            printf("%s\n", command + 5);

        } else if (strncmp(command, "type ", 5) == 0) { 
            // checking for the command 'type' and then saving the rest of the argument provided with type in a pointer to that argument


            char *arg = command + 5; // command + 5 means look for the 5th index of the command variable

            // Now we will check for what is that argument they provided ->

            if (strcmp(arg, "echo") == 0) {
                printf("%s is a shell builtin\n", arg);
            } else if (strcmp(arg, "exit") == 0) {
                printf("%s is a shell builtin\n", arg);
            } else if (strcmp(arg, "type") == 0) {
                printf("%s is a shell builtin\n", arg);
            } else {
                printf("%s: not found\n", arg);
            }
            
        }
        else {
            // Printing the 'command not found' message
            printf("%s: command not found\n", command);
        }

    } while (true);

    return 0;
}