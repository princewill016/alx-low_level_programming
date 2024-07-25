#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function.
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, otherwise exits with an error code
 */
int main(int argc, char *argv[])
{
    int num_bytes, i;
    unsigned char *main_ptr;

    if (argc != 2)
    {
        printf("Error\n");
        exit(1);
    }

    num_bytes = atoi(argv[1]);

    if (num_bytes < 0)
    {
        printf("Error\n");
        exit(2);
    }

    main_ptr = (unsigned char *)main;

    for (i = 0; i < num_bytes; i++)
    {
        printf("%02x", main_ptr[i]);
        if (i < num_bytes - 1)
            printf(" ");
    }
    printf("\n");

    return (0);
}

