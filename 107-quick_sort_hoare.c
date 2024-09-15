#include "sort.h"

/**
 * swap - Swap two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * hoare_partition - Partition the array using Hoare's scheme
 * @array: The array to partition
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot after partitioning
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[low];
    int left = low - 1;
    int right = high + 1;

    while (1)
    {
        do {
            left++;
        } while (array[left] < pivot);

        do {
            right--;
        } while (array[right] > pivot);

        if (left >= right)
            return right;

        swap(&array[left], &array[right]);
        print_array(array, size);
    }
}

/**
 * quick_sort_rec - Recursively sort an array using quick sort
 * @array: The array to sort
 * @low: The starting index of the partition to sort
 * @high: The ending index of the partition to sort
 * @size: The size of the array
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, low, high, size);
        quick_sort_rec(array, low, pivot, size);
        quick_sort_rec(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sort an array of integers using quick sort
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_rec(array, 0, size - 1, size);
}

