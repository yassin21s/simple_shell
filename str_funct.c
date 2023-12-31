#include "shell.h"

/**
 * isWhitespaceString - Check if a string contains only whitespace characters.
 * @str: A pointer to the string to check for whitespace.
 *
 * Return: 5 if the string contains non-whitespace characters, 1 if it consists
 * entirely of whitespace characters, or 0 if 'str' is NULL.
 */

int isWhitespaceString(char *str)
{
	int j;

	if (str == NULL)
		return (0);

	for (j = 0; str[j] != '\0'; j++)
	{

		if (!_isspace((unsigned char)str[j]))
			return (5);
	}

	return (1);
}

/**
 * _isspace - it checks if the str is all white spaces
 * @ch:a str
 * Return: 1 if true else 0
 */

int _isspace(char ch)
{
	return (ch == ' ' || ch == '\t');
}

/**
 * hasSubstring - Check if a string contains a specified substring.
 * @str: it is a pointer to the string to check for the substring.
 *
 * Return: (1) if the substring "/bin/" is found in the string or (0) if not.
 */

int hasSubstring(char *str)
{
	char *substring = "/bin/";
	int str_length = _strlen(str);
	int sub_length = _strlen(substring), i, j, found;

	for (i = 0; i <= str_length - sub_length; i++)
	{
		found = 1;
		for (j = 0; j < sub_length; j++)
		{
			if (str[i + j] != substring[j])
			{
				found = 0;
				break;
			}
		}
		if (found)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _print_str - it print a null-terminated string to standard output.
 * @str: it is a pointer to the null-terminated string to print.
 */

void _print_str(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

/**
 * _concat_whitout_malloc - Concatenate two strings without dma
 * @dest:  a pointer to the destination string where 'src' will be appended.
 * @src: it is a pointer to the source string to be appended to 'dest'.
 *
 * Return: a pointer to the original 'dest' string with 'src' appended to it.
 */

char *_concat_whitout_malloc(char *dest, char *src)
{
	char *original_dest = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (original_dest);
}

