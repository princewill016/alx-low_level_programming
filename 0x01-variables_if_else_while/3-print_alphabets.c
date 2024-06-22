#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the lowercase and uppercase alphabet followed by a newline.
 *              Only putchar function is used, adhering to constraints.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char lowercase = 'a';
    char uppercase = 'A';

    while (lowercase <= 'z')
    {
        putchar(lowercase);  // Print lowercase letter
        lowercase++;         // Move to next lowercase letter
    }

    while (uppercase <= 'Z')
    {
        putchar(uppercase);  // Print uppercase letter
        uppercase++;         // Move to next uppercase letter
    }

    putchar('\n');  // Print newline at the end

    return 0;
}
