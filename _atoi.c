#include "shell.h"

/**
 * check_interactive - Determines if the shell is in interactive mode.
 * @info: Pointer to the information struct.
 *
 * Return: 1 if in interactive mode, 0 otherwise.
 */
int check_interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_custom_delimiter - Checks if a character is a custom delimiter.
 * @c: The character to check.
 * @delimiters: The string of delimiters.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int is_custom_delimiter(char c, char *delimiters)
{
    while (*delimiters)
        if (*delimiters++ == c)
            return (1);
    return (0);
}

/**
 * is_alphabetic - Checks if a character is alphabetic.
 * @c: The character to check.
 *
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */
int is_alphabetic(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

/**
 * convert_to_integer - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: 0 if no numbers in the string, the converted number otherwise.
 */
int convert_to_integer(char *s)
{
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (i = 0; s[i] != '\0' && flag != 2; i++)
    {
        if (s[i] == '-')
            sign *= -1;

        if (s[i] >= '0' && s[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        output = -result;
    else
        output = result;

    return (output);
}
