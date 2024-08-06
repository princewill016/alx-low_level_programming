#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - Deletes the node at index index of a listint_t linked list.
 * @head: Double pointer to the head of the list.
 * @index: The index of the node that should be deleted (starting at 0).
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *temp = *head;
    listint_t *node_to_delete;
    unsigned int count = 0;

    if (head == NULL || *head == NULL)
    {
        return (-1);
    }

    if (index == 0)
    {
        *head = temp->next;
        free(temp);
        return (1);
    }

    while (temp && count < (index - 1))
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL)
    {
        return (-1);
    }

    node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    free(node_to_delete);

    return (1);
}

