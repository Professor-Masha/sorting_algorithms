#ifndef DECK_H
#define DECK_H

/**
 * enum kind_e - Suits of the cards
 * @SPADE: Spades suit
 * @HEART: Hearts suit
 * @CLUB: Clubs suit
 * @DIAMOND: Diamonds suit
 */
typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 * @value: Value of the card (from "Ace" to "King")
 * @kind: Suit of the card (Spade, Heart, Club, Diamond)
 */
typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Node of the deck
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
