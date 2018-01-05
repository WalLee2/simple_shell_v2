#include "shell.h"
/**
 * _getenv - Prints out all the environment variables to standard output
 * @gst: a variable that holds reference to the linked list, user
 * intput, buffer, buffer size, and tokens (tokens dictate how many
 * commands the user input)
 */
void _getenv(global_t *gst)
{
	unsigned int i, j;
	(void)gst;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
			;
		write(1, environ[i], j);
		write(1, "\n", 1);
	}
}
