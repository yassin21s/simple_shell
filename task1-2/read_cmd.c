#include "shell.h"
/**
 * read_cmd - input commad shell
 *
 * Return: stinger.
 */

char *read_cmd(void)
{
	char *array = NULL;
	size_t size_ary = 0;
	ssize_t n_char;

	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$ ", 2);
	n_char = getline(&array, &size_ary, stdin);
	if (n_char == -1)
	{
		free(array), array = NULL;
		return (NULL);
	}
	return (array);
}
