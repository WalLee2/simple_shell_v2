#include "shell.h"
/**
 * _getPATH - function that looks for the environment variable
 * @name: The environment variable to look for
 * Return: The environment value string or NULL if not found.
 */
char *_getPATH(const char *name)
{
	unsigned int i;
	char *token;

	for (i = 0; environ[i] != NULL; i++)
	{
		token = strtok(environ[i], "\n\t =");
		if (_strcmp(token, name))
		{
			return (strtok(NULL, "\n\t "));
		}
	}
	return (NULL);
}
