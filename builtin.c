#include "shell.h"

/**
 * get_builtin - builtin that pais cmd in arg
 * @cmd: command
 * Return: pntr of builtin cmd
 */
int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = 
	{
		{ "env", _env },
		{ "exit", _exitsh },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}

	return (builtin[i].f);
}
