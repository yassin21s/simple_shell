#include "shell.h"
/**
 * print_error - print message.
 * @name_sh: Arguments string
 * @cmd: Arguments vector
 * @index: the counter int
 *
 * Return: Always 0 (Success)
 */
void print_error(char *name_sh, char *cmd, int index)
{
	char *ind, msg[] = ": not found\n";

	ind = n_shell(index);
	write(STDERR_FILENO, name_sh, _strlen(name_sh));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ind, _strlen(ind));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));
	free(ind);
}
/**
 * n_shell - converts an integer to a string.
 * @num: Arguments integer.
 *
 * Return: strings
 */
char *n_shell(int num)
{
	char tab[20];
	int i = 0;

	if (num == 0)
		tab[i++] = '0';
	else
	{
		while (num > 0)
		{
			tab[i++] = (num % 10) + '0';
			num /= 10;
		}
	}
	tab[i] = '\0';
	rev_str(tab, i);
	return (_strdup(tab));
}
/**
 * rev_str - reverse the string.
 * @str: Arguments string.
 * @len: Argumants integer
 *
 * Return: empty
 */
void rev_str(char *str, int len)
{
	char tmp;
	int j = 0;
	int fi = len - 1;

	while (j < fi)
	{
		tmp = str[j];
		str[j] = str[fi];
		str[fi] = tmp;
		j++;
		fi--;
	}
}
/**
 * num_postive - print the string.
 * @str: Arguments string.
 *
 * Return: empty
 */
int num_postive(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0 ; str[i] ; i++)
	{
		if (str[i] < '0' || str[i]  > '9')
			return (0);
	}
	return (1);
}
/**
 * s_shell - reverse the string.
 * @str: Arguments string.
 *
 * Return: integer
 */
int s_shell(char *str)
{
	int i, num = 0;

	for (i = 0 ; str[i] ; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}

