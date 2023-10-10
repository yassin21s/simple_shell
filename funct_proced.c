#include "shell.h"
/**
 * free_split_str - splite string
 * @arg_spt: Arguments string
 *
 * Return: Always 0 (Success)
 */
void free_split_str(char **arg_spt)
{
	int i;

	for (i = 0; arg_spt[i] != NULL; i++)
	{
		free(arg_spt[i]);
	}
	free(arg_spt);
}
