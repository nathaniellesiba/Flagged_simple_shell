#include "shell.h"

extern char **environ;

/*
*print_env - iterate and print environ
*/

void print_env(void)
{
char **env = environ;
while (*env != NULL)
{
printf("%s\n", *env);
env++;
}
}

/*
*starts_with - checks give string
*@str: the string
*@prefix: the prefix
*if it starts with given prefix
*compare length of two strings
*NULL is shorter than prefix
*/

char* starts_with(const char *str, const char *prefix)
{
size_t len_str = strlen(str);
size_t len_prefix = strlen(prefix);
if (len_str < len_prefix)
{
return NULL;
}
if (strncmp(str, prefix, len_prefix) == 0)
{
return (char*)(str + len_prefix);
}
return NULL;
}

/*
*setenv_builtin -  to handle the setenv
*command built-in to the custom shell
*@argc: argument count
*@argv: argument vector
*Return: always 0 on sucess
*/

int setenv_builtin(int argc, char *argv[])
{
if (argc != 3)
{
fprintf(stderr, "setenv: Invalid number of arguments\n");
return 1;
}
char *name = argv[1];
char *value = argv[2];
if (setenv(name, value, 1) != 0)
{
fprintf(stderr, "setenv: Failed to set environment variable\n");
return (1);
}
return (0);
}

int unsetenv_builtin(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "unsetenv: Invalid number of arguments\n");
return 1;
}
char *name = argv[1];
if (unsetenv(name) != 0)
{
fprintf(stderr, "unsetenv: Failed to unset environment variable\n");
return (1);
}
return (0);
}

int main(int argc, char *argv[])
{
/*Example usage of setenv and unsetenv*/
if (setenv("EXAMPLE_VAR", "example_value", 1) != 0)
{
fprintf(stderr, "Failed to set EXAMPLE_VAR\n");
return (1);
}
print_env();

if (unsetenv("EXAMPLE_VAR") != 0)
{
fprintf(stderr, "Failed to unset EXAMPLE_VAR\n");
return 1;
}
print_env();

return (0);
}
