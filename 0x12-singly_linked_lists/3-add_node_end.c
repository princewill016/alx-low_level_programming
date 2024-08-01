#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Double pointer to the head of the list.
 * @str: String to be duplicated and added to the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new_node, *temp;
    char *new_str;

    if (str == NULL)
        return (NULL);

    new_str = strdup(str);
    if (new_str == NULL)
        return (NULL);

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
    {
        free(new_str);
        return (NULL);
    }

    new_node->str = new_str;
    new_node->len = strlen(new_str);
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }

    return (new_node);
}

