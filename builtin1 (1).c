#include "shell.h"

/**
* hstry - displays history list from 0
* @info: char argument
*  Return: Always 0 on success
*/
int hstry(info_t *info)
{
print_list(info->history);
return (0);
}

/**
* unsetalias - sets alias to string
* @info: char argument
* @str: string argument
* Return: Always 0 on ret
*/
int unsetalias(info_t *info, char *str)
{
char *p, c;
int ret;

p = _strchr(str, '=');
if (!p)
return (1);
c = *p;
*p = 0;
ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*p = c;
return (ret);
}

/**
* setalias - sets alias to string
* @info: char argument
* @str: string argument
* Return: Always 0 on success
*/
int setalias(info_t *info, char *str)
{
char *p;

p = _strchr(str, '=');
if (!p)
return (1);
if (!*++p)
return (unset_alias(info, str));

unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
* dsplyalias - display alias string
* @node: node agrument
* Return: Always 0 on success
*/
int dsplyalias(list_t *node)
{
char *p = NULL, *a = NULL;

if (node)
{
p = _strchr(node->str, '=');
for (a = node->str; a <= p; a++)
_putchar(*a);
_putchar('\'');
_puts(p + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
* alias - alias to mimics
* @info: char argument
*  Return: Always 0 on success
*/
int alias(info_t *info)
{
int i = 0;
char *p = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (i = 1; info->argv[i]; i++)
{
p = _strchr(info->argv[i], '=');
if (p)
set_alias(info, info->argv[i]);
else
print_alias(node_starts_with(info->alias, info->argv[i], '='));
}

return (0);
}
