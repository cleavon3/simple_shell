#include "shell.h"
/**
 * interactive - returns code to be true if the shell is in interactive mode
 * @info: the structure address
 * Return: if interactive in mode return 1, 0 otherwise
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if a character is a delimiter
 * @c: character to check
 * @delim: delimiter string
 * Return: if true return 1, if false return 0
 */
int is_delim(char c, char *delim)
{
while (*delim)
{
if (*delim++ == c)
{
return (1);
}
}
return (0);
}
/**
 * _isalpha - checks for an alphabetic character
 * @c: The character to input
 * Return: if c is alphabetic return 1, otherwise return 0
 */
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
{
return (1);
}
else
{
return (0);
}
}
/**
 * _atoi - converts the string to an integer
 * @s: string to be converted
 * Return: if no numbers in string return 0, otherwise converted number
 */
int _atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;

for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
{
sign *= -1;
}
if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
{
flag = 2;
}
}
if (sign == -1)
{
output = -result;
}
else
{
output = result;
}
return (output);
}
