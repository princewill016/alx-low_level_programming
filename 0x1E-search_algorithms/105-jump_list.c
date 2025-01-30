#include "search_algos.h"
#include <math.h>

/**
 * jump_list - searches for value in sorted linked list using Jump search
 * @list: pointer to head of list
 * @size: number of nodes in list
 * @value: value to search for
 * Return: pointer to first node where value is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    size_t step;
    listint_t *prev, *curr;

    if (list == NULL || size == 0)
        return (NULL);

    step = sqrt(size);
    curr = list;
    prev = NULL;

    /* Jump forward */
    while (curr->index + 1 < size && curr->n < value)
    {
        prev = curr;
        for (size_t i = 0; curr->next && i < step; i++)
            curr = curr->next;
        printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
    }

    /* Print search range */
    if (prev)
        printf("Value found between indexes [%lu] and [%lu]\n",
               prev->index, curr->index);
    else
        printf("Value found between indexes [%lu] and [%lu]\n",
               curr->index, curr->index + step);

    /* Linear search in found block */
    curr = prev ? prev : list;
    while (curr && curr->index <= size - 1 && curr->n <= value)
    {
        printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
        if (curr->n == value)
            return (curr);
        curr = curr->next;
    }

    return (NULL);
}
