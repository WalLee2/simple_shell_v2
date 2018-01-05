#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;
/**
 * struct list_s - A struct that represents what each node holds
 * used to store directories found in the PATH
 * @str: The string of each individual directory
 * @strlen: The length of each directory
 * @next: A pointer that points to the next node in the linked list
 */
typedef struct list_s
{
	char *str;
	int strlen;
	struct list_s *next;
} list_t;
/**
 * struct global_s - a struct that contains a reference to the linked list,
 * user intput, buffer, buffer size, and tokens (tokens dictate how many
 * commands the user input)
 * @node: The head of a linked list
 * @usrIn: Buffer used to hold the user input (commands)
 * @buf: Buffer that is used for getline which will automatically resize
 * if both buf is NULL and bufsz (buffer size) is 0
 * @bufsz: The buffer size of buf
 * @num_tokens: Number of tokens that the user has provided (spaced words,
 * flags, and or other arguments that are separated by spaces)
 */
typedef struct global_s
{
	list_t *node;
	char **usrIn;
	char *buf;
	size_t bufsz;
	int num_tokens;
} global_t;
/**
 * struct builtin_s - A struct used for an array of structs for finding builtin
 * commands should the user type one
 * @str: The string representation of the builtin
 * @f: Function pointer to the corresponding builtin command
 */
typedef struct builtin_s
{
	char *str;
	void (*f)(global_t *);
} builtin_t;

/** free **/
void free_chunk(global_t *gst);
void free_list(list_t **head);
void free_all(global_t *gst);

/** string manipulation **/
int _strcmp(const char *s1, const char *s2);
void _strcpy_mult_src(char *dest, char *src1, char *src2);
void _strcpy_one_src(char *dest, char *src);

/** error handling **/
void error_usrIn(global_t *gst);
void error_PATH(global_t *gst);
void error_ll(global_t *gst);

/** etc **/
void *_memset(void *s, int b, size_t n);

/** Linked list **/
int add_to_linked_list(list_t **head, char *directory);

/**builtin functions **/
void _getenv(global_t *gst);

/** shell functions **/
global_t *initialize(global_t *gst);
int tokenize_insert(global_t *gst);
void parse_PATH_add(global_t *gst);
char *_getPATH(const char *name);
void parse_dirs_add(global_t *gst, char *directories);
int find_command(global_t *gst, char *command, int len);
int append_execute(global_t *gst);
void execute(char *command, char **arr_of_words);

#endif
