#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm volatile ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}

#include "shell.h"

/**
 * main - Entry point for the shell program.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int ac, char **av)
{
    info_t info[] = {INFO_INIT}; // Initialize an array of info_t structures.
    int fd = 2; // Default file descriptor for input (stdin).

    // Inline assembly to modify the file descriptor.
    asm volatile(
        "mov %1, %0\n\t"
        "add $3, %0"
        : "=r"(fd)
        : "r"(fd));

    if (ac == 2)
    {
        // If a command file is provided, open it for reading.
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
        {
            if (errno == EACCES)
                exit(126); // Exit with status 126 on permission error.
            if (errno == ENOENT)
            {
                _eputs(av[0]);
                _eputs(": 0: Can't open ");
                _eputs(av[1]);
                _eputchar('\n');
                _eputchar(BUF_FLUSH);
                exit(127); // Exit with status 127 if the file does not exist.
            }
            return EXIT_FAILURE; // Exit with failure status on other errors.
        }
        info->readfd = fd; // Set the file descriptor for input in info struct.
    }

    populate_env_list(info); // Populate the environment list.
    read_history(info);      // Read command history.
    hsh(info, av);           // Start the shell.
    return EXIT_SUCCESS;     // Return success status.
}
