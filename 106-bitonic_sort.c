#include "sort.h"
#include <stdio.h>

/**
 * swap_ints - Swaps two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * bitonic_compare - Compares and swaps elements for bitonic sort
 * @array: Array of integers
 * @size: Total size of the array
 * @i: The first index to compare
 * @j: The second index to compare
 * @dir: The direction (1 for ascending, 0 for descending)
 */
void bitonic_compare(int *array, size_t size, int i, int j, int dir)
{
    if (dir == (array[i] > array[j]))
    {
        swap_ints(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * bitonic_merge - Recursively merges subarrays in bitonic sequence
 * @array: Array of integers
 * @size: Size of the full array
 * @low: Starting index of the subarray
 * @cnt: Number of elements in the subarray
 * @dir: The direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, int low, int cnt, int dir)
{
    if (cnt > 1)
    {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++)
            bitonic_compare(array, size, i, i + k, dir);
        bitonic_merge(array, size, low, k, dir);
        bitonic_merge(array, size, low + k, k, dir);
    }
}

/**
 * bitonic_sort_rec - Recursively sorts a bitonic sequence
 * @array: Array of integers
 * @size: Size of the full array
 * @low: Starting index of the subarray
 * @cnt: Number of elements in the subarray
 * @dir: The direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_rec(int *array, size_t size, int low, int cnt, int dir)
{
    if (cnt > 1)
    {
        int k = cnt / 2;

        printf("Merging [%d/%lu] (%s):\n", cnt, size, dir ? "UP" : "DOWN");
        print_array(array + low, cnt);

        bitonic_sort_rec(array, size, low, k, 1);      /* Sort in ascending order */
        bitonic_sort_rec(array, size, low + k, k, 0);  /* Sort in descending order */
        bitonic_merge(array, size, low, cnt, dir);
        
        printf("Result [%d/%lu] (%s):\n", cnt, size, dir ? "UP" : "DOWN");
        print_array(array + low, cnt);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the Bitonic sort algorithm
 * @array: Array of integers to be sorted
 * @size: Size of the array (must be a power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    bitonic_sort_rec(array, size, 0, size, 1);
}
