#include "shell.h"
/**
 * parse_PATH_add - Find the PATH value in the array of pointers pointed to
 * by environ
 * @gst: a variable that holds reference to the linked list, user
 * intput, buffer, buffer size, and tokens (tokens dictate how many
 * commands the user input)
 */
void parse_PATH_add(global_t *gst)
{
	char *directories;

	directories = _getPATH("PATH");
	if (directories == NULL)
	{
		error_PATH(gst);
	}
	parse_dirs_add(gst, directories);
}

/**
 * parse_dirs_add - parse directories from PATH and add to
 * linked list
 * @gst: a variable that holds reference to the linked list, user
 * intput, buffer, buffer size, and tokens (tokens dictate how many
 * commands the user input)
 * @directories: Variable that holds reference to all directories in PATH
 */
void parse_dirs_add(global_t *gst, char *directories)
{
	char *token;
	int status;

	token = strtok(directories, "\n\t :");
	status = 1;
	while (token != NULL && status)
	{
		status = add_to_linked_list(&gst->node, token);
		if (!status)
		{
			error_ll(gst);
		}
		token = strtok(NULL, "\n\t :");
	}
}
/**
 * find_command_execute - if the user passed a command that does not include
 * the directory that the command can be found, append the command to a list
 * of directories found in the PATH. If the user passes the command with
 * the directory, check if it exists and run it if it does.
 * @gst: a variable that holds reference to the linked list, user
 * intput, buffer, buffer size, and tokens (tokens dictate how many
 * commands the user input)
 * @command: user command, example, /bin/ls -l or ls -l
 * @len: The length of the command
 * Return: 0 if the command doesn't exist or 1 otherwise
 */
int find_command_execute(global_t *gst, char *command, int len)
{
	list_t *current;
	char *new;
	struct stat st;

	current = *(&gst->node);
	if (_strcmp("/", command) == 0)
	{
		while (current != NULL)
		{
			new = malloc((current->strlen + len) * sizeof(*new));
			_strcpy_mult_src(new, current->str, command);
			if (stat(new, &st) == 0)
			{
				execute(new, gst->usrIn);
				free(new);
				return (1);
			}
			free(new);
			current = current->next;
		}
	}
	if (stat(command, &st) == -1)
	{
		perror("Command does not exist!\n");
		free_chunk(gst);
		return (0);
	}
	execute(command, gst->usrIn);
	return (1);
}
/**
 * append_execute - Grab the command that the user entered and get the
 * length of it. Pass the command and the length to check if the command
 * exists.
 * @gst: a variable that holds reference to the linked list, user
 * intput, buffer, buffer size, and tokens (tokens dictate how many
 * commands the user input)
 * Return: 0 if the command exists and 1 if it doesn't
 */
int append_execute(global_t *gst)
{
	char *command;
	int len, status;

	if (gst->usrIn[0] == NULL)
	{
		perror("gst->usrIn[0] == NULL!\n");
		free_all(gst);
	}
	command = gst->usrIn[0];
	for (len = 0; command[len] != '\0'; len++)
		;
	len++;
	status = find_command_execute(gst, command, len);
	if (status == 0)
	{
		return (1);
	}
	return (0);
}
