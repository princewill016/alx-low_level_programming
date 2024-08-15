#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * create_file - creates a file and writes text_content to it
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 * 
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
    int fd;
    ssize_t bytes_written;
    size_t length = 0;

    if (filename == NULL)
        return (-1);

    if (text_content != NULL)
    {
        while (text_content[length] != '\0')
            length++;
    }

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
        return (-1);

    if (text_content != NULL)
    {
        bytes_written = write(fd, text_content, length);
        if (bytes_written != (ssize_t)length)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}

