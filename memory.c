#include "shell.h"

/**
 * bfree - Frees a pointer and sets it to NULL.
 * @ptr: Address of the pointer to be freed.
 *
 * This function frees the memory allocated for a pointer and sets the pointer
 * itself to NULL to prevent any potential use of the freed memory.
 *
 * Return: 1 if the pointer was successfully freed, 0 otherwise.
 */
int bfree(void **ptr)
{
    // Check if the pointer exists and is not already NULL.
    if (ptr && *ptr)
    {
        free(*ptr); // Free the memory.
        *ptr = NULL; // Set the pointer to NULL.
        return 1;    // Return success status.
    }
    return 0; // Return failure status.
}
