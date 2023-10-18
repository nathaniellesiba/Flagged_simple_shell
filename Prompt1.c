#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
*main - to diplay prompt
*Return: always 0
*/

int main(void)
{
char command[MAX_COMMAND_LENGTH];
int status;

while (1)
{
printf(">> ");

/*Read the command from the user*/
if (fgets(command, sizeof(command), stdin) == NULL)
{
printf("\n");
break;
}

/*Remove the newline character*/
command[strcspn(command, "\n")] = '\0';

/*Fork a child process*/
pid_t pid = fork();

if (pid < 0)
{
perror("Fork failed");
exit(1);
}
else if (pid == 0)
{
/*Child process*/

/*Execute the command*/
if (execlp(command, command, NULL) == -1)
{
perror("Command execution failed");
exit(1);
}
}
else
{
/*Parent process*/

/*Wait for the child process to complete*/
waitpid(pid, &status, 0);
}
}

return (0);
}
