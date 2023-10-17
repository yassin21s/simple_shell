#include "shell.h"
/**
 * main - Entry point of function simple shell
 * @ac: Argumants int
 * @argv: Arguments vector
 *
 * Return: Always 0 (Success)
 */
int main(int ac, char **argv)
{
	int status;
	char **arg_spt = NULL;
	char *array = NULL;
	(void)ac;

	while (1)
	{
		array = read_cmd();
		if (array == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		arg_spt = split_str(array);
		if (!arg_spt)
			continue;
		status = ececut_cmd(arg_spt, argv);
	}
	return (0);
}
