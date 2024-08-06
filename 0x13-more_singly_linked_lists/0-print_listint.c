#include "lists.h"

/* Prototype for _putchar */
int _putchar(char c);

/* Helper function to print an integer */
void print_number(int n)
{
    char buffer[10];
    int i = 0;
    int j;
    int is_negative = 0;

    if (n < 0)
    {
        is_negative = 1;
        n = -n;
    }

    if (n == 0)
    {
        _putchar('0');
        return;
    }

    while (n > 0)
    {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }

    if (is_negative)
    {
        _putchar('-');
    }

    for (j = i - 1; j >= 0; j--)
    {
        _putchar(buffer[j]);
    }
}

/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
    size_t count = 0;

    while (h)
    {
        print_number(h->n);
        _putchar('\n');
        count++;
        h = h->next;
    }

    return (count);
}

