#include "shell.h"

/**
 * builtin_hndl - Handle Builtin Command
 * @cmd: the command
 * @er:status of last Excute
 * Return: Always 0 on success
 */

int builtin_hndl(char **cmd, int er)
{
	 bul_t bil[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp(cmd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->fun(cmd, er));
		}
		i++;
	}
	return (-1);
}
/**
 * cmd_checker - Exc Cmd Fork,Wait,Exc
 *
 * @cmd:Parsed Command
 * @input: the command
 * @c: count of exc time
 * @argv:argument vector, Program Name
 * Return: always 0
 */
int cmd_checker(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * signal_hndl - Handle signal
 * @sig:Captured Signal
 * Return: 0 or void
 */
void signal_hndl(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
