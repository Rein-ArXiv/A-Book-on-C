/* Chapter 9 exercise 18 */

/* poker 프로그램에서 assign_values() 함수의 다음과 같은 버전을 보자.

    void assign_value(card c, int pips, cdhs suit)
    {
        c.pips = pips;
        c.suit = suits;
    }

 * 이 함수를 검사하기 위해 다음 코드를 수행시키면, 예상한 결과가 나오지 않음을
 * 알 수 있을 것이다. 왜 그런지 설명하여라.
 
    card c;
    
    assign_values(c, 13, diamonds);     // the king of diamonds
    prn_card_values(&c);

 */


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
void assign_value(card c, int pips, cdhs suit); // Should use pointer. look underline.
// void assign_value_ptr(card *c, int pips, cdhs suit);
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

void assign_value(card c, int pips, cdhs suit)
{
    c.pips = pips;
    c.suit = suits;
}

/*

void assign_value_ptr(card *c, int pips, cdhs suit)
{
    c -> pips = pips;
    c -> suit = suits;
}

*/