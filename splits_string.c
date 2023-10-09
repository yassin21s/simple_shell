#include "shell.h"
/**
 * split_str - splite string
 * @array: Arguments string
 *
 * Return: Always 0 (Success)
 */
char **split_str(char *array)
{
	char **arg_spt;
	char *token;
	int i = 0;

	arg_spt = malloc(1024 * sizeof(char));
	if (arg_spt == NULL)
	{
		perror("Erreur array arg_spt");
		exit(EXIT_FAILURE);
	}

	token = strtok(array, " \t\n");
		while (token)
		{
			arg_spt[i] = strdup(token);
			if (arg_spt == NULL)
			{
				perror("Erreur array arg_spt_tok");
				exit(EXIT_FAILURE);
			}
			token = strtok(NULL, " \t\n");
			i++;
		}
		arg_spt[i] = NULL;
		return (arg_spt);
}
