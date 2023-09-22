#include "shell.h"

/**
**_strncpy - copy of a string
*@dest: copying destination
*@src: str source
*@n: copied char amount
*Return: concatenated str
*/
char *_strncpy(char *dest, char *src, int n)
{
int i, j;
char *s = dest;

i = 0;
while (src[i] != '\0' && i < n - 1)
{
dest[i] = src[i];
i++;
}
if (i < n)
{
j = i;
while (j < n)
{
dest[j] = '\0';
j++;
}
}
return (s);
}

/**
**_strncat - string concatenater
*@dest: string 1 arguments
*@src: string 2 arguments
*@n: max bit used
*Return: concatenated str
*/
char *_strncat(char *dest, char *src, int n)
{
int i, j;
char *s = dest;

i = 0;
j = 0;
while (dest[i] != '\0')
i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (s);
}

/**
**_strchr - locates char str
*@s: parsed string
*@c: char arguments
*Return: pointer to memory area
*/
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');

return (NULL);
}

/**
* _exitsh - exit the shell
*
* @datash: data relevant (status and args)
* Return: 0 on success.
*/
int _exitsh(data_shell *datash)
{
    unsigned int ustat;
    int is_digit;
    int str_len;
    int big_number;

    if (datash->args[1] != NULL)
    {
        ustat = _atoi(datash->args[1]);
        is_digit = _isdigit(datash->args[1]);
        str_len = _strlen(datash->args[1]);
        big_number = ustat > (unsigned int)INT_MAX;
        if (!is_digit || str_len > 10 || big_number)
        {
            get_error(datash, 2);
            datash->status = 2;
            return (1);
        }
        datash->status = (ustat % 256);
    }
    return (0);
}
