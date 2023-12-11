#include "shell.h"

/**
 * _memset - Fills the first n bytes of the memory area pointed to by s with
 * the constant byte b.
 * @s: The pointer to the memory area to be filled.
 * @b: The value to be set (as an unsigned char).
 * @n: The number of bytes to be filled.
 *
 * Return: The modified pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;

    if (s)
    {
        for (i = 0; i < n; i++)
            s[i] = b;
    }
    return (s);
}

/**
 * ffree - Frees a null-terminated array of strings and the array itself.
 * @pp: The pointer to the array of strings.
 */
void ffree(char **pp)
{
    char **a = pp;

    if (pp)
    {
        while (*pp)
            free(*pp++);
        free(a);
    }
}

/**
 * _realloc - Changes the size of the memory block pointed to by ptr to the
 * specified new size.
 * @ptr: The pointer to the memory block to be reallocated.
 * @old_size: The current size of the memory block.
 * @new_size: The new size for the memory block.
 *
 * Return: The pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *p;

    if (!ptr)
        return (malloc(new_size));
    if (new_size == 0)
    {
        free(ptr);
        return (NULL);
    }
    if (new_size == old_size)
        return (ptr);

    p = malloc(new_size);
    if (!p)
        return (NULL);

    old_size = (old_size < new_size) ? old_size : new_size;
    while (old_size--)
        p[old_size] = ((char *)ptr)[old_size];
    free(ptr);
    return (p);
}
