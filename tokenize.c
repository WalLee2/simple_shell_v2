#include "shell.h"
/**
 * builtin_check - Check to see if the token the user
 * entered is a builtin function
 * @gst: a variable that holds reference to the linked list, user
 * intput, buffer, buffer size, and tokens (tokens dictate how many
 * commands the user input) * Return: Size of the array
 * @token: The keyword to be evaluated
 * Return: 1 if a builtin exists and 0 otherwise
 */
int builtin_check(global_t *gst, char *token)
{
	builtin_t b[] = {
		{"exit", free_all},
		{"env", _getenv},
/*
 *		{"setenv", _setenv},
 *		{"unsetenv", _unsetenv},
 *		{"cd", _cd},
 *		{"alias", _alias},
 *		{"help", _help},
 *		{"history", _history},
 */
	};
	size_t size, i;

	size = sizeof(b) / sizeof(b[0]);
	for (i = 0; i < size; i++)
	{
		if (_strcmp(b[i].str, token))
		{
			b[i].f(gst);
			return (1);
		}
	}
	return (0);
}


/**
 * tokenize_insert - Strip the user input of spaces, new lines, and or tabs and
 * store them
 * @gst: a variable that holds reference to the linked list, user
 * intput, buffer, buffer size, and tokens (tokens dictate how many
 * commands the user input) * Return: Size of the array
 */
int tokenize_insert(global_t *gst)
{
	char *token;
	size_t i;

	token = strtok(gst->buf, "\n\t ");
	if (token == NULL)
	{
		return (-1);
	}
	if (builtin_check(gst, token))
	{
		return (0);
	}
	for (i = 0; token != NULL; i++)
	{
		gst->usrin[i] = token;
		token = strtok(NULL, "\n\t ");
	}
	return (i);
}
