#include "shell.h"

/**
 * is_cmd - Checks if the given path corresponds to an executable file.
 * @info: The information struct containing potential arguments.
 * @path: The path to check.
 *
 * Return: 1 if the path corresponds to an executable file, 0 otherwise.
 */
int is_cmd(info_t *info, char *path)
{
    struct stat st;

    (void)info;
    if (!path || stat(path, &st) != 0)
        return (0);

    if (S_ISREG(st.st_mode))
    {
        return (1);
    }
    return (0);
}

/**
 * dup_chars - Creates a duplicate string of characters from the given range.
 * @pathstr: The source string.
 * @start: The starting index of the range.
 * @stop: The stopping index (exclusive) of the range.
 *
 * Return: A duplicate string containing characters from the specified range.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
    static char buf[1024];
    int i = 0, k = 0;

    for (k = 0, i = start; i < stop; i++)
        if (pathstr[i] != ':')
            buf[k++] = pathstr[i];
    buf[k] = '\0';
    return (buf);
}

/**
 * find_path - Finds the full path of a command within the specified path string.
 * @info: The information struct containing potential arguments.
 * @pathstr: The colon-separated path string.
 * @cmd: The command to find.
 *
 * Return: The full path of the command if found, NULL otherwise.
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
    int i = 0, curr_pos = 0;
    char *path;

    if (!pathstr)
        return (NULL);

    if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
    {
        if (is_cmd(info, cmd))
            return (cmd);
    }

    while (1)
    {
        if (!pathstr[i] || pathstr[i] == ':')
        {
            path = dup_chars(pathstr, curr_pos, i);
            if (!*path)
                _strcat(path, cmd);
            else
            {
                _strcat(path, "/");
                _strcat(path, cmd);
            }
            if (is_cmd(info, path))
                return (path);

            if (!pathstr[i])
                break;

            curr_pos = i;
        }
        i++;
    }
    return (NULL);
}
