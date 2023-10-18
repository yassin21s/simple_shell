#include "shell.h"
/**
 * free_array - splite string
 * @array: Arguments string
 *
 * Return: Always 0 (Success)
 */
void free_array(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0 ; array[i] != NULL ; i++)
	{
		free(array[i]), array[i] = NULL;
	}
	free(array), array = NULL;
}
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
