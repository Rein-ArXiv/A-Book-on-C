/* In file poker.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define    NDEALS    3000   // number of deals
#define    NPLAYERS  6      // number of players

typedef    enum {clubs, diamonds, hearts, spades} cdhs;

struct card {
    int pips;
    cdhs suit;
};

typedef struct card card;

card assign_values(int pips, cdhs suit);
void prn_card_values(card *c_ptr);
void play_poker(card deck[52]);
void shuffle(card deck[52]);
void swap(card *p, card *q);
void deal_the_cards(card deck[52], card hand[NPLAYERS][5]);
int  is_flush(card h[5]);

int main(void)
{
    cdhs suit;
    int i, pips;
    card deck[52];

    for (i = 0; i < 52; ++i) {
        pips = i % 13 + 1;
        if (i < 13)
            suit = clubs;
        else if (i < 26)
            suit = diamonds;
        else if (i < 39)
            suit = hearts;
        else
            suit = spades;
        deck[i] = assign_values(pips, suit);
    }

    for (i = 26; i < 39; ++i)           // print out the hearts
        prn_card_values(&deck[i]);
    play_poker(deck);
    return 0;
}

card assign_values(int pips, cdhs suit)
{
    card c;

    c.pips = pips;
    c.suit = suit;
    return c;
}

void prn_card_values(card *c_ptr)
{
    int pips = c_ptr -> pips;
    cdhs suit = c_ptr -> suit;
    char *suit_name;

    if (suit == clubs)
        suit_name = "clubs";
    else if (suit == diamonds)
        suit_name = "diamonds";
    else if (suit == hearts)
        suit_name = "hearts";
    else if (suit == spades)
        suit_name = "spades";
    printf("card: %2d of %s\n", pips, suit_name);
}

void play_poker(card deck[52])
{
    int flush_cnt = 0, hand_cnt = 0;
    int i, j;
    card hand[NPLAYERS][5];      // each player dealt 5 cards

    srand(time(NULL));

    for (i = 0; i < NDEALS; ++i) {
        shuffle(deck);
        deal_the_cards(deck, hand);
        for (j = 0; j < NPLAYERS; j++){
            ++hand_cnt;
            if (is_flush(hand[j])) {
                ++flush_cnt;
                printf("%s%d\n%s%d\n%s%f\n\n",
                    "      Hand number: ", hand_cnt,
                    "     Flush number: ", flush_cnt,
                    "Flush probability: ", (double) flush_cnt / hand_cnt);
            }
        }
    }
}

void shuffle(card deck[52])
{
    int i, j;

    for (i = 0; i < 52; ++i) {
        j = rand() % 52;
        swap(&deck[i], &deck[j]);
    }
}

void swap(card *p, card *q)
{
    card tmp;

    tmp = *p;
    *p = *q;
    *q = tmp;
}

void deal_the_cards(card deck[52], card hand[NPLAYERS][5])
{
    int card_cnt = 0, i, j;

    for (j = 0; j < 5; ++j)
        for (i = 0; i < NPLAYERS; ++i)
            hand[i][j] = deck[card_cnt++];
}

int is_flush(card h[5])
{
    int i;

    for (i = 1; i < 5; ++i)
        if (h[i].suit != h[0].suit)
            return 0;
    return 1;
}