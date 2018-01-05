#include "shell.h"
/**
 * initialize - Initialize all the variables in the struct
 * @gst: a variable that holds reference to the linked list, user
 * intput, buffer, buffer size, and tokens (tokens dictate how many
 * commands the user input)
 * Return: A pointer pointing to the struct
 */
global_t *initialize(global_t *gst)
{
	gst = malloc(sizeof(*gst));
	if (gst == NULL)
	{
		perror("gst malloc failed!\n");
		_exit(1);
	}
	gst->node = NULL;
	gst->buf = NULL;
	gst->bufsz = 0;
	gst->num_tokens = 0;
	return (gst);
}
