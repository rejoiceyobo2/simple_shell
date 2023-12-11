#include "shell.h"

/**
 * _strcpy - Copies a string from source to destination.
 * @dest: Destination string.
 * @src: Source string.
 *
 * Return: Pointer to the destination string.
 */
char *_strcpy(char *dest, char *src) {
    int i = 0;

    if (dest == src || src == 0)
        return (dest);
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}

/**
 * _strdup - Duplicates a string.
 * @str: String to be duplicated.
 *
 * Return: A pointer to the newly allocated duplicate string.
 */
char *_strdup(const char *str) {
    int length = 0;
    char *ret;

    if (str == NULL)
        return (NULL);
    while (*str++)
        length++;
    ret = malloc(sizeof(char) * (length + 1));
    if (!ret)
        return (NULL);
    for (length++; length--;)
        ret[length] = *--str;
    return (ret);
}

/**
 * _puts - Prints a string to standard output.
 * @str: String to be printed.
 */
void _puts(char *str) {
    int i = 0;

    if (!str)
        return;
    while (str[i] != '\0') {
        _putchar(str[i]);
        i++;
    }
}

/**
 * _putchar - Writes a character to the standard output.
 * @c: Character to be written.
 *
 * Return: 1 on success, or -1 on failure.
 */
int _putchar(char c) {
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE) {
        write(1, buf, i);
        i = 0;
    }
    if (c != BUF_FLUSH)
        buf[i++] = c;
    return (1);
}
