#include "shell.h"
/**
 * bool_ean - input command shell exits_env_exit status_setenv
 * @cmd: argumants string.
 *
 * Return: empty.
 */
int bool_ean(char *cmd)
{
	int i;
	char *tab_bool[] = {"exit", "setenv", "env", NULL};

	for (i = 0 ; tab_bool[i] ; i++)
	{
		if (_strcmp(cmd, tab_bool[i]) == 0)
			return (1);
	}
	return (0);
}
/**
 * bool_funct - use command exits_env_exit status_setenv
 * @cmd: argumants string
 * @argv: argumants vector
 * @status: stat
 * @idx: index integre
 *
 * Return: empty.
 */
void bool_funct(char **cmd, char **argv, int *status, int idx)
{

	if (_strcmp(cmd[0], "exit") == 0)
		exit_sh(cmd, argv, status, idx);
	else if (_strcmp(cmd[0], "env") == 0)
		print_env(cmd, status);

}
/**
 * exit_sh - use command exits
 * @cmd: argumants string
 * @argv:argumants vecteur
 * @status: stat
 * @idx: the counter int.
 *
 * Return: empty.
 */
void exit_sh(char **cmd, char **argv, int *status, int idx)
{
	char *cmpt;
	int ex_val = (*status);
	char tab_msg[] = "exit: Illegal number: ";

	if (cmd[1])
	{
		if (num_postive(cmd[1]))
		{
			ex_val = s_shell(cmd[1]);
		}
		else
		{
			cmpt = n_shell(idx);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, cmpt, _strlen(cmpt));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, tab_msg, _strlen(tab_msg));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(cmpt);
			free_array(cmd);
			(*status) = 2;
			return;
		}
	}
	free_array(cmd);
	exit(ex_val);
}
/**
 * print_env - use command env
 * @cmd: argumants string
 * @status: stat
 *
 * Return: empty.
 */
void print_env(char **cmd, int *status)
{
	int i;

	for (i = 0 ; environ[i] ; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_array(cmd);
	(*status) = 0;
}
