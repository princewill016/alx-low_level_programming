#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Prints a struct dog
 * @d: Pointer to struct dog to print
 *
 * Description: Prints the details of a dog. If an element is NULL, 
 * prints (nil) instead. If d is NULL, prints nothing.
 */
void print_dog(struct dog *d)
{
    if (d != NULL)
    {
        if (d->name == NULL)
            printf("Name: (nil)\n");
        else
            printf("Name: %s\n", d->name);

        printf("Age: %f\n", d->age);

        if (d->owner == NULL)
            printf("Owner: (nil)\n");
        else
            printf("Owner: %s\n", d->owner);
    }
}
