#include "shell.h"
/**
 * _memset - a function that fills memory with a constant byte.
 * @s: a pointer that points to the memory area
 * @b: a constant byte
 * @n: a fixed number of bytes
 * Return: pointer to the beginning of the memory area s
 */
void *_memset(void *s, int b, size_t n)
{
	unsigned int *ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = b;
		n--;
		ptr++;
	}
	return (s);
}
