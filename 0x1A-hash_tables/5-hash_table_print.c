#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht: The hash table to print
 *
 * Description: Prints key/value pairs in order they appear in array
 * Format: {'key': 'value', 'key': 'value', ...}
 */
void hash_table_print(const hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *current;
    int first_pair = 1;  /* Flag to manage commas */

    /* If ht is NULL, don't print anything */
    if (ht == NULL)
        return;

    printf("{");
    for (i = 0; i < ht->size; i++)
    {
        current = ht->array[i];
        while (current != NULL)
        {
            if (!first_pair)
                printf(", ");
            printf("'%s': '%s'", current->key, current->value);
            first_pair = 0;
            current = current->next;
        }
    }
    printf("}\n");
}
