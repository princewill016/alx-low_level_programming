#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: Double pointer to the head of the list.
 * @idx: The index of the list where the new node should be added (starting at 0).
 * @n: The integer value to be added to the new node.
 *
 * Return: The address of the new node, or NULL if it failed or the index is invalid.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new_node, *temp = *head;
    unsigned int count = 0;

    if (head == NULL)
    {
        return (NULL);
    }

    if (idx == 0)
    {
        return (add_nodeint(head, n));
    }

    new_node = (listint_t *)malloc(sizeof(listint_t));
    if (new_node == NULL)
    {
        return (NULL);
    }
    
    new_node->n = n;

    while (temp && count < (idx - 1))
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        free(new_node);
        return (NULL);
    }

    new_node->next = temp->next;
    temp->next = new_node;

    return (new_node);
}

