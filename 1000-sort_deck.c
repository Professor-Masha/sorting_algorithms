#include <stdlib.h>
#include <string.h>
#include "deck.h"

int card_value(const char *value) {
    const char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    for (int i = 0; i < 13; i++) {
        if (strcmp(value, values[i]) == 0)
            return i;
    }
    return -1; // Should never reach here
}

int compare_cards(const void *a, const void *b) {
    const deck_node_t *node_a = *(const deck_node_t **)a;
    const deck_node_t *node_b = *(const deck_node_t **)b;

    if (node_a->card->kind != node_b->card->kind) {
        return node_a->card->kind - node_b->card->kind;
    } else {
        return card_value(node_a->card->value) - card_value(node_b->card->value);
    }
}

void sort_deck(deck_node_t **deck) {
    if (!deck || !*deck)
        return;

    // Count the number of nodes (52 in this case)
    size_t count = 0;
    deck_node_t *current = *deck;
    while (current) {
        count++;
        current = current->next;
    }

    // Create an array of node pointers
    deck_node_t **array = malloc(count * sizeof(deck_node_t *));
    if (!array)
        return;

    current = *deck;
    for (size_t i = 0; i < count; i++) {
        array[i] = current;
        current = current->next;
    }

    // Sort the array using qsort
    qsort(array, count, sizeof(deck_node_t *), compare_cards);

    // Rebuild the doubly linked list
    for (size_t i = 0; i < count; i++) {
        array[i]->prev = (i == 0) ? NULL : array[i - 1];
        array[i]->next = (i == count - 1) ? NULL : array[i + 1];
    }

    // Update the deck head
    *deck = array[0];

    // Free the temporary array
    free(array);
}

