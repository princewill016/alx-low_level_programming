#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - prints numbers, followed by a new line.
 * @separator: string to be printed between numbers
 * @n: number of integers passed to the function
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
    va_list args;
    unsigned int i;
    int num;

    va_start(args, n);

    for (i = 0; i < n; i++)
    {
        num = va_arg(args, int);
        if (separator != NULL && i > 0)
            printf("%s", separator);
        printf("%d", num);
    }

    va_end(args);
    printf("\n");
}

