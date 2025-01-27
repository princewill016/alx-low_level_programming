#include "search_algos.h"
#include <stdio.h>

/**
 * binary_search_exp - binary search helper for exponential search
 * @array: pointer to first element of array
 * @start: start index
 * @end: end index
 * @value: value to search for
 * Return: index where value is located, or -1 if not found
 */
int binary_search_exp(int *array, size_t start, size_t end, int value)
{
    size_t i;

    while (start <= end)
    {
        printf("Searching in array: ");
        for (i = start; i <= end; i++)
        {
            printf("%d", array[i]);
            if (i < end)
                printf(", ");
        }
        printf("\n");

        i = start + (end - start) / 2;
        if (array[i] == value)
            return (i);
        if (array[i] < value)
            start = i + 1;
        else
            end = i - 1;
    }
    return (-1);
}

/**
 * exponential_search - searches for value using Exponential search
 * @array: pointer to first element of array
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;
    size_t end;

    if (array == NULL || size == 0)
        return (-1);

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    end = bound < size - 1 ? bound : size - 1;
    printf("Value found between indexes [%lu] and [%lu]\n", bound/2, end);
    return binary_search_exp(array, bound/2, end, value);
}
