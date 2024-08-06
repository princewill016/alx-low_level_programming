#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a listint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: The address of the node where the loop starts, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow = head;
    listint_t *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            listint_t *entry = head;

            while (entry != slow)
            {
                entry = entry->next;
                slow = slow->next;
            }

            return (entry);
        }
    }

    return (NULL);
}

