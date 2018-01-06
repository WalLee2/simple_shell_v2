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
	unsigned int i, j;

	if (s1 == NULL || s2 == NULL)
	{
		return (0);
	}
	for (i = 0; s1[i] != '\0'; i++)
		;
	for (j = 0; s2[j] != '\0'; j++)
		;
	if (i >= j)
	{
		for (i = 0; s1[i] != '\0'; i++)
		{
			if (s1[i] != s2[i])
			{
				return (0);
			}
		}
	}
	else if (i < j)
	{
		for (j = 0; s2[j] != '\0'; j++)
		{
			if (s2[j] != s1[j])
			{
				return (0);
			}
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

	if (src != NULL && dest != NULL)
	{
		for (i = 0; src[i] != '\0'; i++)
		{
			dest[i] = src[i];
		}
		dest[i] = '\0';
	}
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

	if (src1 != NULL && src2 != NULL && dest != NULL)
	{
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
}
