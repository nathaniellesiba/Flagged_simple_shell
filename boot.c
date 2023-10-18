#include "shell.h"

/**
*tswoke - returns in interactive mode
*@info: struct address
*Return: interactive mode
*/
int tswoke(info_t *info)
{
int isInteractive = 0;

if (isatty(STDIN_FILENO))
{
if (info->readfd <= 2)
{
isInteractive = 1;
}
}

return (isInteractive);
}

/**
*tsdelmt - delimeter char checker
*@c: char argument
*@delim: delimeter string
*Return: 1 on true, 0 on false
*/
int tsdelmt(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}
