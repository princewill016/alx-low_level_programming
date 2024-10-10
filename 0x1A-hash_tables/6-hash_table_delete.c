#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table to delete
 *
 * Description: Frees all memory associated with the hash table
 * including nodes, strings, array, and the table structure itself
 */
void hash_table_delete(hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *current, *temp;

    /* Check if hash table is NULL */
    if (ht == NULL)
        return;

    /* Free all nodes and their contents */
    for (i = 0; i < ht->size; i++)
    {
        current = ht->array[i];
        while (current != NULL)
        {
            temp = current->next;  /* Save next pointer before freeing */
            free(current->key);    /* Free the key string */
            free(current->value);  /* Free the value string */
            free(current);         /* Free the node itself */
            current = temp;        /* Move to next node */
        }
    }

    /* Free the array and the hash table structure */
    free(ht->array);
    free(ht);
}
