#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: Size of the array
 *
 * Return: Pointer to the newly created hash table
 *         NULL if something went wrong
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *new_table;
    unsigned long int i;

    /* Check if size is 0 */
    if (size == 0)
        return (NULL);

    /* Allocate memory for the hash table structure */
    new_table = malloc(sizeof(hash_table_t));
    if (new_table == NULL)
        return (NULL);

    /* Allocate memory for the array of pointers */
    new_table->array = malloc(sizeof(hash_node_t *) * size);
    if (new_table->array == NULL)
    {
        free(new_table);
        return (NULL);
    }

    /* Initialize all elements to NULL */
    for (i = 0; i < size; i++)
        new_table->array[i] = NULL;

    new_table->size = size;

    return (new_table);
}
