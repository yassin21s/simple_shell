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
	char *pathcmd, *array = NULL;
	size_t size_ary = 0;
	int status, n_char = 0;
	char **arg_spt = NULL;
	pid_t pid;
	(void)ac, (void)av;

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

				pid = fork();
				if (pid == 0)
				{
				pathcmd = getpathcmd(arg_spt[0]);
				if (pathcmd)
					execve(pathcmd, arg_spt, env);
				else
				printf("not found\n");
				free(pathcmd);
				}
				else
				wait(&status);
				free(array);
				free(arg_spt);
				}
	return (0);
}
