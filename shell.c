#include "shell.h"
/**
 * sig_handler - Handles when the user presses ctrl c to try to exit.
 * The way to exit is by using the exit builtin command
 * @signo: The desired signature to be handled differently
 */
void sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}
/**
 * main - write "$ " to standard output and wait for the user to enter
 * a command. Once command is entered it will try to see if it's a builtin
 * command. If it's not than it will try to search for the command in the PATH.
 * Execute the command if found or return an error message and free certain
 * dynamically allocated space.
 * Return: Zero
 */
int main(void)
{
	global_t *gst;

	gst = NULL;
	gst = initialize(gst);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		if (getline(&gst->buf, &gst->bufsz, stdin) != -1)
		{
			gst->usrIn = malloc(gst->bufsz * sizeof(*gst->usrIn));
			if (gst->usrIn == NULL)
			{
				error_usrIn(gst);
			}
			_memset(gst->usrIn, 0, gst->bufsz);
			gst->num_tokens = tokenize_insert(gst);
			if (gst->num_tokens == -1 || gst->num_tokens == 0)
			{
				free(gst->usrIn);
				continue;
			}
			if (gst->node == NULL)
			{
				parse_PATH_add(gst);
			}
			if (append_execute(gst))
			{
				continue;
			}
		}
		free_chunk(gst);
	}
	return (0);
}
