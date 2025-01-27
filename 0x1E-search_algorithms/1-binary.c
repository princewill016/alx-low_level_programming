#include "search_algos.h"
#include <stdio.h>

/**
 * binary_search - searches for value in sorted array using Binary search
 * @array: pointer to first element of array to search
 * @size: number of elements in array
 * @value: value to search for
 * Return: index where value is located, or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
    size_t left = 0;
    size_t right = size - 1;
    size_t mid, i;

    if (array == NULL)
        return (-1);

    while (left <= right)
    {
        printf("Searching in array: ");
        for (i = left; i <= right; i++)
        {
            printf("%d", array[i]);
            if (i < right)
                printf(", ");
        }
        printf("\n");

        mid = (left + right) / 2;

        if (array[mid] == value)
            return (mid);
        if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (-1);
}
