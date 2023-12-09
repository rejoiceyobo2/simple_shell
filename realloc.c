#include "shell.h"

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

