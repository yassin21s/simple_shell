#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	pid_t pid;
	int i = 0;
	int status;

	char *args[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0 ; i < 5 ; i++)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
		exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("execve");
					exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}
	exit(EXIT_SUCCESS);
}
