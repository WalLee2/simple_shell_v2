#include "shell.h"
/**
 * add_to_linked_list - adds each directory entry found in the PATH to a node
 * in a linked list
 * @head: A double pointer to the beginning of the list
 * @directory: A single directory in the PATH
 * Return: 1 on successfully adding the node and 0 otherwise
 */
int add_to_linked_list(list_t **head, char *directory)
{
	list_t *new;
	int i;

	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		perror("Failed to malloc a new node!\n");
		return (0);
	}
	for (i = 0; directory[i] != '\0'; i++)
		;
	i++;
	new->str = malloc(i * sizeof(*new->str));
	if (new->str == NULL)
	{
		free(new);
		perror("Failed to malloc for the string in a node!\n");
		return (0);
	}
	new->strlen = i;
	_strcpy_one_src(new->str, directory);
	if (head == NULL)
	{
		(*head) = new;
		new->next = NULL;
	}
	else
	{
		new->next = (*head);
		(*head) = new;
	}
	return (1);
}
