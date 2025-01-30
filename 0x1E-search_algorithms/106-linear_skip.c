#include "search_algos.h"
#include <math.h>

/**
 * linear_skip - searches for a value in a sorted skip list
 * @list: pointer to the head of the skip list
 * @value: value to search for
 * Return: pointer to the first node where value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current, *prev;

    if (list == NULL)
        return (NULL);

    current = list;
    prev = list;

    /* Traverse the express lane */
    while (current->express && current->n < value)
    {
        prev = current;
        current = current->express;
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
    }

    /* If we've reached the end of express lane */
    if (!current->express && current->n < value)
    {
        prev = current;
        while (current->next)
            current = current->next;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", 
           prev->index, current->index);

    /* Linear search in the identified range */
    current = prev;
    while (current && current->n <= value)
    {
        printf("Value checked at index [%lu] = [%d]\n", 
               current->index, current->n);
        if (current->n == value)
            return (current);
        current = current->next;
    }

    return (NULL);
}
