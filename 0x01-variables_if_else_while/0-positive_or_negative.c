#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: Size of the array
 *
 * Return: Pointer to the newly created hash table, NULL if something went wrong
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *ht;
    unsigned long int i;

    if (size == 0)
        return (NULL);

    /* Allocate memory for the hash table structure */
    ht = malloc(sizeof(hash_table_t));
    if (ht == NULL)
        return (NULL);

    /* Allocate memory for the array of pointers */
    ht->array = malloc(sizeof(hash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    /* Initialize all elements to NULL */
    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    ht->size = size;

    return (ht);
}
