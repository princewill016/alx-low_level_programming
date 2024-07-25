#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything based on the format string.
 * @format: a list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
    va_list args;
    unsigned int i = 0;
    char *str;
    char c;
    int i_num;
    float f;

    va_start(args, format);

    while (format && format[i])
    {
        if (i > 0)
            printf(", ");

        if (format[i] == 'c')
        {
            c = va_arg(args, int);
            printf("%c", c);
        }
        else if (format[i] == 'i')
        {
            i_num = va_arg(args, int);
            printf("%d", i_num);
        }
        else if (format[i] == 'f')
        {
            f = va_arg(args, double);  /* float is promoted to double */
            printf("%f", f);
        }
        else if (format[i] == 's')
        {
            str = va_arg(args, char *);
            if (str == NULL)
                printf("(nil)");
            else
                printf("%s", str);
        }
        i++;
    }

    va_end(args);
    printf("\n");
}

