#include "shell.h"
/**
 * split_str - splite string
 * @array: Arguments string
 * @detr: Arguments determenante
 *
 * Return: Always 0 (Success)
 */
char **split_str(char *array, char *detr)
{
	char *arg_spt;
	char *token;
	int i = 0;

	arg_spt = malloc(1024 * sizeof(char));

	token = strtok(array, detr)
		while (token)
		{
			arg_spt[i] = token;
			token = strtok(NULL, "detr");
			i++;
		}


}
