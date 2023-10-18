#include "shell.h"

/**
* print_env - display current environment
* @info: char argument
* Return: Always 0 on success
*/

void print_env(info_t *info)
{
list_t *node = info->env;

while (node) {
printf("%s\n", node->str);
node = node->next;
}
}


/*
**getenv - get value of environment variable
* @name: environment variable name
* @info: char argument

* Return: Always 0 on success
*/

char *getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *p;

while (node) {
p = starts_with(node->str, name);
if (p && *p)
return p;
node = node->next;
}

return (NULL);
}
