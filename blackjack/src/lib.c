//#include <inttypes.h>
//#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    int money;
} Player;

// Only used for Drawing Purposes
typedef struct {
    int id;
    int value;
    int suit;
} Card;

typedef struct {
    int *card_position;
    int size;
} Deck;

int get_bet(int *bp);
int get_card_suit(int card);
int get_card_id(int card);
int get_card_value(int card);
void shuffle(Deck deck);
void merge_shuffle(int array[], int size);
// Debug Functions
void print_card(int card);
void print_deck(Deck deck);

// Return int > 0
int get_bet(int *bp) 
{
    scanf_s("%d", bp);
    if (bp > 0) return 1;
    else return 0;
}

// Return 0-3 Hearts, Diamonds, Spades, Clubs
int get_card_suit(int card) 
{
    return card/13;
}

// Return ID = [0-12] | Card Face
int get_card_id(int card)
{
    return card%13;
}

// Return Card Value or -1
int get_card_value(int card)
{
    int id = get_card_id(card);
    int res = -1;
    if (id == 13) res = 11;   // Ass
    if (id >= 8) res = 10;    // Bube, Dame, Koenig
    if (id <= 8) res = id+2;  // 2-10
    return res;
}


void shuffle(Deck deck) 
{
    merge_shuffle(deck.card_position, deck.size);
}

// shuffle deck random
void shuffle_bad(Deck deck)
{
    if (deck.size < 1) return;

    int *copy = (int*) malloc(deck.size * sizeof(int));
    srand(time(NULL));
    for (int i=0; i < deck.size-1; ++i)
    {
        // Random Number [i, deck.size-1]
        int j = (rand() % (deck.size - 1)) ;
        const int temp = deck.card_position[i];
        deck.card_position[i] = deck.card_position[j];
        print_card(deck.card_position[i]);
        print_card(deck.card_position[j]);
    }
}

// Debug Functions
void print_card(int card) 
{
    printf("CardID: %d | Value: %d | Symbol: %d \n", get_card_id(card), get_card_value(card), get_card_suit(card));
}

// Print Deck for Debug
void print_deck(Deck deck) 
{
    for (int i = 0; i < deck.size; ++i) 
    {
        printf("Deck Pos: %d | CardID: %d | Value: %d | Symbol: %d | int:%d\n", i, 
               get_card_id(deck.card_position[i]),
               get_card_value(deck.card_position[i]), 
               get_card_suit(deck.card_position[i]), 
               deck.card_position[i]);
    }
}

// =================================================================
// UTIL

// Merge Sort for Int Arrays
void merge_shuffle(int array[], int size)
{
    if(size > 1)
    {
        srand(time(NULL));
        int left_arr[size/2];
        int right_arr[(size + 1)/2];
        int i;

        for(i = 0; i < size/2; ++i) 
            left_arr[i] = array[i];

        for(i = size/2; i < size; ++i) 
            right_arr[i - size/2] = array[i];

        merge_shuffle(left_arr,size/2);
        merge_shuffle(right_arr,(size + 1)/2);

        int *pos1 = &left_arr[0];
        int *pos2 = &right_arr[0];

        for(i = 0; i < size; ++i)
        {
            if(rand()%2 == 0)
            {
                array[i] = *pos1;
                if (pos1 != &right_arr[(size+1)/2 - 1]) 
                { // pos1 nicht verändern, wenn der größte Wert mehrmals vorkommt
                    if(pos1 == &left_arr[size/2 - 1])
                    {
                        pos1 = &right_arr[(size+1)/2 - 1];
                    }
                    else ++pos1;
                }
            }
            else
            {
                array[i] = *pos2;
                if(pos2 == &right_arr[(size + 1)/2 - 1])
                {
                    pos2 = &left_arr[size/2 - 1];
                }
                else ++pos2;
            }
        }
    }
}
// Merge Sort for Int Arrays
void merge_sort(int array[], int size){
    if(size > 1)
    {
        int left_arr[size/2];
        int right_arr[(size + 1)/2];
        int i;

        for(i = 0; i < size/2; ++i)
            left_arr[i] = array[i];

        for(i = size/2; i < size; ++i)
            right_arr[i - size/2] = array[i];

        merge_sort(left_arr,size/2);
        merge_sort(right_arr,(size + 1)/2);

        int *pos1 = &left_arr[0];
        int *pos2 = &right_arr[0];

        for(i = 0; i < size; ++i)
        {
            if(*pos1 <= *pos2)
            {
                array[i] = *pos1;
                if (pos1 != &right_arr[(size+1)/2 - 1]) 
                { // pos1 nicht verändern, wenn der größte Wert mehrmals vorkommt
                    if(pos1 == &left_arr[size/2 - 1])
                    {
                        pos1 = &right_arr[(size+1)/2 - 1];
                    }
                    else ++pos1;
                }
            }
            else
            {
                array[i] = *pos2;
                if(pos2 == &right_arr[(size + 1)/2 - 1])
                {
                    pos2 = &left_arr[size/2 - 1];
                }
                else ++pos2;
            }
        }
    }
}
