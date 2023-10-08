#include "shell.h"
/**
 * main - Entry point of function simple shell
 * @ac: Argumants int
 * @av: Arguments vector
 * @env: The global variable
 *
 * Return: Always 0 (Success)
 */
int main(int ac, char **av, char **env)
{
	char *array = NULL;
	size_t size_ary = 0;
	int i, n_char = 0;
	char **arg_spt = NULL;
	(void)ac;
	(void)av;
	(void)env;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);
		n_char = getline(&array, &size_ary, stdin);
		if (n_char == -1)
		{
			if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
			exit(1);
			free(array);
		}

		arg_spt = split_str(array);
		for (i = 0 ; arg_spt[i] != NULL  ; i++)
		{
			printf("%s", arg_spt[i]);
			free(arg_spt[i]);
		}
		

		free(array);
		free(arg_spt);
	}
	return (0);
}
