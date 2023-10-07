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
	ssize_t size_ary = 0;
	int n_char = 0;
	char **arg_spt;
	char *detr = " \t\n";
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
		printf("%s", array);
		free(array);
	}
	return (0);
}
