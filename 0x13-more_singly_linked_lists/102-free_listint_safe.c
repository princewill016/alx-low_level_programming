#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: Double pointer to the head of the list.
 *
 * Return: The number of nodes that were freed.
 */
size_t free_listint_safe(listint_t **h)
{
    listint_t *temp;
    listint_t *prev;
    size_t count = 0;
    listint_t *slow = *h, *fast = *h;

    if (h == NULL || *h == NULL)
    {
        return (0);
    }

    while (*h)
    {
        if (slow == fast && count > 0)
        {
            break;
        }

        prev = *h;
        *h = (*h)->next;
        free(prev);
        count++;
        slow = slow->next;
        fast = fast->next;
        if (fast && fast->next)
        {
            fast = fast->next;
        }
    }

    *h = NULL;

    return (count);
}

