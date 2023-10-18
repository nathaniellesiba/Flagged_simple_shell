#include "shell.h"

/**
 * tsexit - shell exiting state
 * @info: state char argument
 * Return: always 0 on success of state
 */
int tsexit(info_t *info)
{
if (info->argv[1])
{
int exitcheck = _erratoi(info->argv[1]);
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = exitcheck;
return (-2);
}
info->err_num = -1;
return (-2);
}
