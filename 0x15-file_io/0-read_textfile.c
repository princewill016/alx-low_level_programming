#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters it could read and print, 0 if fails.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd; /* File descriptor */
    ssize_t bytes_read, bytes_written;
    char *buffer;

    if (filename == NULL) /* Check for NULL filename */
        return 0;

    fd = open(filename, O_RDONLY); /* Open file in read-only mode */
    if (fd == -1) /* Check for open failure */
        return 0;

    buffer = malloc(sizeof(char) * BUF_SIZE); /* Allocate buffer */
    if (buffer == NULL) /* Check for malloc failure */
    {
        close(fd); /* Close file on allocation failure */
        return 0;
    }

    bytes_read = 0;
    while (letters > 0 && (bytes_read = read(fd, buffer, BUF_SIZE)) > 0)
    {
        bytes_written = write(STDOUT_FILENO, buffer, bytes_read); /* Write to stdout */
        if (bytes_written != bytes_read) /* Check for write failure */
        {
            free(buffer); /* Free buffer on write failure */
            close(fd); /* Close file on write failure */
            return 0;
        }

        letters -= bytes_read; /* Update remaining letters to read */
    }

    free(buffer); /* Free buffer */
    close(fd); /* Close file */

    if (bytes_read == -1) /* Check for read error */
        return 0;

    return bytes_written; /* Return total bytes written */
}
