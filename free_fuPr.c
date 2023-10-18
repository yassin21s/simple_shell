#include "shell.h"
/**
 * free_array - free array
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
