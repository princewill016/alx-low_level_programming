#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 *         Exits with status 98 if it fails.
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow = head, *fast = head;
    size_t count = 0;
    int is_loop = 0;

    while (head)
    {
        if (is_loop)
        {
            printf("-> [%p] %d\n", (void *)head, head->n);
        }
        else
        {
            printf("[%p] %d\n", (void *)head, head->n);
        }

        count++;
        head = head->next;

        if (head == NULL)
        {
            return (count);
        }

        slow = head;
        fast = head->next;

        while (fast && fast != slow)
        {
            fast = fast->next;
            if (fast == slow)
            {
                is_loop = 1;
                break;
            }
        }
    }

    exit(98);
}

