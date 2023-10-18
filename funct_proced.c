#include "shell.h"
/**
 * _strdup - The duplicate the string.
 * @str: input string.
 *
 * Return: return strings.
 */
char *_strdup(const char *str)
{
	char *ptr;
	int i, ctp = 0;

	if (str == NULL)
		return (NULL);
	while (str[ctp])
		ctp++;
	ptr = malloc(sizeof(char) * (ctp + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0 ; i <= ctp ; i++)
		ptr[i] = str[i];
	return (ptr);
}
/**
 * _strcmp - Compare two strings.
 * @str1: input string1.
 * @str2: input string2.
 *
 * Return: return cmp  .
 */
int _strcmp(char *str1, char *str2)
{
	int cmp;

	cmp = (int)*str1 - (int)*str2;
	while (*str1)
	{
		if (*str1 != *str2)
			break;
		str1++;
		str2++;
		cmp = (int)*str1 - (int)*str2;
	}
	return (cmp);
}
/**
 * _strlen - the length of a string.
 * @str: the string.
 *
 * Return: return int  .
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}
/**
 * _strcat - Concatenate the strings.
 * @dest: string1.
 * @src: string2.
 *
 * Return: return strings  .
 */
char *_strcat(char *dest, char *src)
{
	char *pte = dest;

	while (*pte)
		pte++;
	while (*src)
	{
		*pte = *src;
		pte++;
		src++;
	}
	*pte = '\0';
	return (dest);
}
/**
 * _strcpy - Copy the string.
 * @dest: string1.
 * @src: string2.
 *
 * Return: return strings  .
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
