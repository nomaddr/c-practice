#include "lib.c"

void print_arr(int array[], int size);

// ==============================================================
// MAIN =========================================================
int main() {
    puts("Play BlackJack");

    Deck deck;
    deck.size = 52;
    deck.card_position = (int*) malloc(deck.size * (sizeof(int)));

    // Init deck
    for (int i = 0; i < deck.size; i++) 
    {
        deck.card_position[i] = i;
    }

    print_deck(deck);
    shuffle(deck);
    print_deck(deck);

    return 0;
}
// ==============================================================

void print_arr(int array[], int size)
{
    for (int i=0; i < size; ++i)
    {
        printf("Position: %d | Value: %d\n", i, array[i]);
    }
}
