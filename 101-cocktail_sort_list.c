#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @left: The left node to be swapped
 * @right: The right node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
    if (left->prev)
        left->prev->next = right;
    else
        *list = right;

    if (right->next)
        right->next->prev = left;

    left->next = right->next;
    right->prev = left->prev;

    right->next = left;
    left->prev = right;
    print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the
 * Cocktail shaker sort algorithm
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *start = *list, *end = NULL;

    if (!list || !*list || !(*list)->next)
        return;

    do {
        swapped = 0;
        while (start->next != end) {
            if (start->n > start->next->n) {
                swap_nodes(list, start, start->next);
                swapped = 1;
            } else {
                start = start->next;
            }
        }
        end = start;
        if (!swapped)
            break;

        swapped = 0;
        while (start->prev != NULL) {
            if (start->n < start->prev->n) {
                swap_nodes(list, start->prev, start);
                swapped = 1;
            } else {
                start = start->prev;
            }
        }
    } while (swapped);
}
