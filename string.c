#include "shell.h"

/**
 * _strlen - Computes the length of a string.
 * @s: Pointer to the input string.
 *
 * Return: Length of the string.
 */
int _strlen(char *s) {
    int i = 0;

    if (!s)
        return (0);

    while (*s++)
        i++;
    return (i);
}

/**
 * _strcmp - Compares two strings.
 * @s1: First string for comparison.
 * @s2: Second string for comparison.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2) {
    while (*s1 && *s2) {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    if (*s1 == *s2)
        return (0);
    else
        return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - Checks if a string starts with another string.
 * @haystack: The string to check if it starts with needle.
 * @needle: The prefix string.
 *
 * Return: If needle is a prefix of haystack, returns a pointer to the character
 * in haystack just after the prefix; otherwise, returns NULL.
 */
char *starts_with(const char *haystack, const char *needle) {
    while (*needle)
        if (*needle++ != *haystack++)
            return (NULL);
    return ((char *)haystack);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string where src will be appended.
 * @src: The source string to be appended to dest.
 *
 * Return: A pointer to the destination string.
 */
char *_strcat(char *dest, char *src) {
    char *ret = dest;

    while (*dest)
        dest++;
    while (*src)
        *dest++ = *src++;
    *dest = *src;
    return (ret);
}
