#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    // Flush after every printf
    setbuf(stdout, NULL);

    do {
        // TODO: Uncomment the code below to pass the first stage
        printf("$ ");

        // Waiting for user input
        char command[1024];
        fgets(command, sizeof(command), stdin);
        // Removing newlines from the user provided command
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0) {
      exit(EXIT_SUCCESS);
    }
        if (strncmp(command, "echo ", 5) == 0) {
            printf("%s\n ", command + 5);

        } else {
            // Printing the 'command not found' message
            printf("%s: command not found\n", command);
        }

    } while (true);

    return 0;
}