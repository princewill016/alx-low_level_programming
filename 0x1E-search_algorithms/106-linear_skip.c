#include "search_algos.h"
#include <stdio.h>

/**
 * recursive_binary - recursive implementation of binary search
 * @array: pointer to first element of array
 * @left: left index of current subarray
 * @right: right index of current subarray
 * @value: value to search for
 * Return: index where value is located, or -1 if not found
 */
int recursive_binary(int *array, size_t left, size_t right, int value)
{
    size_t i;
    size_t mid = left + (right - left) / 2;

    if (left > right)
        return (-1);

    printf("Searching in array: ");
    for (i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i < right)
            printf(", ");
    }
    printf("\n");

    if (array[mid] == value && (mid == left || array[mid - 1] != value))
        return (mid);
    if (array[mid] >= value)
        return recursive_binary(array, left, mid, value);
    return recursive_binary(array, mid + 1, right, value);
}

/**
 * advanced_binary - searches for first occurrence of value using Binary search
 * @array: pointer to first element of array
 * @size: number of elements in array
 * @value: value to search for
 * Return: index where value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    return recursive_binary(array, 0, size - 1, value);
}
