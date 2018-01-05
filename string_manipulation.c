#include "shell.h"
/**
 * _strcmp - compares two strings character by character
 * @s1: First string
 * @s2: Second string
 * Return: 0 if the character in one string doesn't match the second
 * 1 otherwise
 */
int _strcmp(const char *s1, const char *s2)
{
	unsigned int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
	}
	return (1);
}

/**
 * _strcpy_one_src - copy characters from source to destination
 * @dest: Where the characters are being copied to
 * @src: Where the characters are being copied from
 */
void _strcpy_one_src(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
}

/**
 * _strcpy_mult_src - concatinate string 1 with string 2 separated by a
 * back slash / and store it in the destination
 * @dest: Space allocated for the newly formed string
 * @src1: Variable that holds string 1
 * @src2: Variable that holds string 2
 */
void _strcpy_mult_src(char *dest, char *src1, char *src2)
{
	int i, j;

	for (i = 0; src1[i] != '\0'; i++)
	{
		dest[i] = src1[i];
	}
	dest[i] = '/';
	i++;
	for (j = 0; src2[j] != '\0'; i++, j++)
	{
		dest[i] = src2[j];
	}
	dest[i] = '\0';
}
