#include "shell.h"
/**
 * split_str - splite string
 * @array: Arguments string
 *
 * Return: Always 0 (Success)
 */
char **split_str(char *array)
{
	char **arg_spt = NULL;
	char *token, *tmp;
	int i = 0, j = 0;

	if (array == NULL)
		return (NULL);
	tmp = _strdup(array);
	token = strtok(tmp, " \t\n");
	if (!token)
	{
		free(array), array = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		j++;
		token = strtok(NULL, " \t\n");
	}
	free(tmp), tmp = NULL;
	arg_spt = malloc(sizeof(char *) * (j + 1));
	if (!arg_spt)
	{
		free(array), array = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	token = strtok(array, " \t\n");
	while (token)
	{
	arg_spt[i] = _strdup(token);
	token = strtok(NULL, " \t\n");
	i++;
	}
	arg_spt[i] = NULL;
	free(array), array = NULL;
	return (arg_spt);
}
