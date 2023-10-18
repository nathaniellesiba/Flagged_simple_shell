#include "shell.h"


#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

int main(void)
{
char command[MAX_COMMAND_LENGTH];
char* args[MAX_ARGS];
int i, num_args;

while (1)
{
/*Remove trailing newline*/
printf("Enter a command: ");
fgets(command, sizeof(command), stdin);
command[strcspn(command, "\n")] = '\0';

/*Parse the command and arguments*/
args[0] = strtok(command, " ");
num_args = 1;
while ((args[num_args] = strtok(NULL, " ")) != NULL)
{
num_args++;
}

/*Fork a child process*/
pid_t pid = fork();

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/*Child process executes the command*/
execvp(args[0], args);
perror("execvp");
exit(EXIT_FAILURE);
}
else
{
/*Parent process waits for the child to finish*/
wait(NULL);
}
}

return (0);
}


/**
*prompt1Display - first printf
*prompt2Display - second printf
*/

void prompt1Display(void)
{
    fprintf(stderr, "$ ");
}

void prompt2Display(void)
{
    fprintf(stderr, "> ");
}
