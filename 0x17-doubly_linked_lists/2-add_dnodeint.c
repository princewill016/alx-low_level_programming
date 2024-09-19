#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: double pointer to the head of the list
 * @n: the value to be added to the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
    dlistint_t *new_node;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    /* Initialize the new node's data */
    new_node->n = n;
    new_node->prev = NULL; /* New node will be the first, so no previous node */
    new_node->next = *head; /* Point to the current head of the list */

    /* If the list is not empty, set the previous head's prev to the new node */
    if (*head != NULL)
        (*head)->prev = new_node;

    /* Move the head to point to the new node */
    *head = new_node;

    return (new_node);
}
