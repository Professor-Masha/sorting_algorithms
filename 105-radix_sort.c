#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_max - Finds the maximum number in the array
 * @array: Array of integers
 * @size: Size of the array
 * Return: The maximum number
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return (max);
}

/**
 * counting_sort_radix - Sorts an array based on the current digit
 * @array: Array of integers
 * @size: Size of the array
 * @exp: The digit place to sort on (1, 10, 100, etc.)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
    int *output, count[10] = {0};
    size_t i;

    output = malloc(size * sizeof(int));
    if (!output)
        return;

    /* Count occurrences of each digit */
    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Update the count array to contain actual positions */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (i = size; i > 0; i--)
    {
        output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
        count[(array[i - 1] / exp) % 10]--;
    }

    /* Copy sorted elements into the original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    /* Free memory and print array */
    free(output);
    print_array(array, size);
}

/**
 * radix_sort - Sorts an array using the Radix sort algorithm (LSD)
 * @array: Array of integers to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (!array || size < 2)
        return;

    /* Find the maximum number to know the number of digits */
    max = get_max(array, size);

    /* Perform counting sort for each digit */
    for (exp = 1; max / exp > 0; exp *= 10)
        counting_sort_radix(array, size, exp);
}

