#include "shell.h"
/**
 * execute - run the command within the arr_of_words in the child process
 * while the parent process waits for the child to complete.
 * @command: The command to be ran
 * @arr_of_words: Array that holds user input
 */
void execute(char *command, char **arr_of_words)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("Child process returned -1!\n");
	}
	if (child == 0)
	{
		if (execve(command, arr_of_words, NULL) == -1)
		{
			perror("An error occurred when executing!\n");
		}
	}
	else
	{
		wait(&status);
	}
}
