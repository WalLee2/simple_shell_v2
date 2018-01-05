#include "shell.h"
/**
 * free_chunk - Free dynamically allocated space for user input and buffer
 * as well as reset the same buffer, number of tokens, and buffer size.
 * @gst: a variable that holds reference to the linked list, user
 * intput, buffer, buffer size, and tokens (tokens dictate how many
 * commands the user input)
 */
void free_chunk(global_t *gst)
{
	free(gst->usrIn);
	free(gst->buf);
	gst->buf = NULL;
	gst->num_tokens = 0;
	gst->bufsz = 0;
}
/**
 * free_list - Free the linked list if head is not NULL
 * @head: A double pointer that points to the beginning of the linked list
 */
void free_list(list_t **head)
{
	list_t *current;

	while (*head != NULL)
	{
		current = *head;
		*head = (*head)->next;
		free(current->str);
		free(current);
	}
}
/**
 * free_all - Free all dynamically allocated space including the struct
 * @gst: a variable that holds reference to the linked list, user
 * intput, buffer, buffer size, and tokens (tokens dictate how many
 * commands the user input)
 */
void free_all(global_t *gst)
{

	free_chunk(gst);
	if (gst->node != NULL)
	{
		free_list(&gst->node);
	}
	free(gst);
	_exit(1);
}
