#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array using the Counting sort algorithm
 * @array: Array of integers to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count_array, *output_array;
    int max = 0;
    size_t i;

    if (!array || size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < size; i++)
        if (array[i] > max)
            max = array[i];

    /* Allocate memory for the count array and output array */
    count_array = malloc((max + 1) * sizeof(int));
    output_array = malloc(size * sizeof(int));
    if (!count_array || !output_array)
        return;

    /* Initialize the count array */
    for (i = 0; i <= (size_t)max; i++)
        count_array[i] = 0;

    /* Count occurrences of each element */
    for (i = 0; i < size; i++)
        count_array[array[i]]++;

    /* Print the counting array */
    print_array(count_array, max + 1);

    /* Update the count array to contain positions */
    for (i = 1; i <= (size_t)max; i++)
        count_array[i] += count_array[i - 1];

    /* Build the output array */
    for (i = size; i > 0; i--) {
        output_array[count_array[array[i - 1]] - 1] = array[i - 1];
        count_array[array[i - 1]]--;
    }

    /* Copy sorted elements into the original array */
    for (i = 0; i < size; i++)
        array[i] = output_array[i];

    /* Free memory */
    free(count_array);
    free(output_array);
}
