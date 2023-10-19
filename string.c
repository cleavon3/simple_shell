#include "shell.h"
/**
 * _strlen - Calculates the length of a string.
 * @s: The input string.
 * Return: The length of the string.
 */
int _strlen(char *s)
{
int i = 0;
if (!s)
return (0);
while (*s++)
i++;
return (i);
}
/**
 * _strcmp - Compares two strings lexicographically.
 * @s1: The first string.
 * @s2: The second string.
 * Return: Negative if s1 < s2, positive if s1 > s2, or 0 if equal.
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
return (*s1 == *s2 ? 0 : (*s1 < *s2 ? -1 : 1));
}
/**
 * starts_with - Checks if a string starts with a prefix.
 * @haystack: The input string.
 * @needle: The prefix to find.
 * Return: Pointer to the next character in haystack or NULL.
 */
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}
/**
 * _strcat - Concatenates two strings.
 * @dest: The destination buffer.
 * @src: The source buffer.
 * Return: Pointer to the destination buffer.
 */
char *_strcat(char *dest, char *src)
{
char *ret = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
