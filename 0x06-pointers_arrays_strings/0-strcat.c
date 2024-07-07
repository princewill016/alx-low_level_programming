#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
    int i, j;

    // Find the end of the destination string
    for (i = 0; dest[i] != '\0'; i++)
        ;

    // Append the source string to the destination string
    for (j = 0; src[j] != '\0'; j++, i++)
    {
        dest[i] = src[j];
    }

    // Add the terminating null byte
    dest[i] = '\0';

    return dest;
}

