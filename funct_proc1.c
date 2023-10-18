#include "shell.h"
/**
 * _strdup - The duplicate the string.
 * @str: input string.
 *
 * Return: return strings.
 */
char *_strdup(char *str)
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
/**
 * _strncmp - it compare the first 'n' characters of two strings.
 * @str1: It is a pointer to the first string to compare.
 * @str2: It is a pointer to the second string to compare.
 * @n: Is the maximum number of characters to compare.
 *
 * Return: 0 always success
 */

int _strncmp(char *str1, char *str2, size_t n)
{
	unsigned char char1;
	unsigned char char2;

	while (n > 0 && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		n--;
	}

	if (n == 0)
	{
		return (0);
	}

	char1 = *(unsigned char *)str1;
	char2 = *(unsigned char *)str2;

	if (char1 < char2)
	{
		return (-1);
	}
	else if (char1 > char2)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

