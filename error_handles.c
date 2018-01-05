#include "shell.h"
/**
 * error_usrIn - Free dynamically allocated space, print an error message,
 * and exit when an error occurs before allocating space for finding the PATH.
 * @gst: a variable that holds reference to the linked list, user
 * intput, buffer, buffer size, and tokens (tokens dictate how many
 * commands the user input)
 */
void error_usrIn(global_t *gst)
{
	free(gst->buf);
	free(gst);
	gst->bufsz = 0;
	perror("gst->usr_in malloc failed!\n");
	_exit(1);
}
/**
 * error_PATH - Print an error message, free all allocated space, and exit
 * when searching the PATH
 * @gst: a variable that holds reference to the linked list, user
 * intput, buffer, buffer size, and tokens (tokens dictate how many
 * commands the user input)
 */
void error_PATH(global_t *gst)
{
	perror("PATH is empty!\n");
	free_all(gst);
}
/**
 * error_ll - Print an error message, free all allocated space, and exit
 * when an error has occured when adding to the linked list.
 * @gst: a variable that holds reference to the linked list, user
 * intput, buffer, buffer size, and tokens (tokens dictate how many
 * commands the user input)
 */
void error_ll(global_t *gst)
{
	perror("An error occured adding to the Linked List!\n");
	free_all(gst);
}
