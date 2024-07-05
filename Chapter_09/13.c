/* Chapter 9 exercise 13 */

/* 9.6절의 poker 프로그램을 가지고 계속 실험해보자. 여러 번 패를 분배한 후에 플
 * 러시가 나올 최종적인 확률은 수학적 확률에 근사해야 한다. 플러시가 나올 수학
 * 적 확률은 다음과 같이 계산될 수 있다. 예를 들어 첫 카드가 하트였다고 가정하
 * 자. 지금 카드덱에 51장의 카드가 있고, 그 카드들 중 하트는 12장이므로, 두 번째
 * 도 하트일 확률은 12/51이다. 세 번째 카드가 또 하트일 확률은 현재 카드덱에 50
 * 장의 카드가 있고, 그 카드 중에서 하트는 11장이므로 (12/51) * (11/50)이다. 이
 * 런 방법으로 계속 진행하면, 플러시가 나올 수학적 확률은 다음과 같다.

    (12/51) * (11/50) * (10/49) * (9/48) 

 * 이것은 약 0.00198이다. (이 값을 계산기를 사용하여 검사해 보아라.) 컴퓨터로
 * poker 게임을 수행시킬 때, 계산되는 확률은 이 수치보다 크거나 작을 것이다. 실
 * 험해 보고 어떤 경우인지 알아보아라.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NDEALS 3000    // number of deals
#define NPLAYERS 6     // number of players

typedef enum {clubs, diamonds, hearts, spades} cdhs;

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
int is_flush(card h[5]);

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

    printf("Hearts cards in the deck:\n");
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
    int pips = c_ptr->pips;
    cdhs suit = c_ptr->suit;
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
                printf("      Hand number: %d\n", hand_cnt);
                printf("     Flush number: %d\n", flush_cnt);
                printf("Flush probability: %.5f\n\n", (double) flush_cnt / hand_cnt);
            }
        }
    }

    printf("Total hands dealt: %d\n", hand_cnt);
    printf("Total flushes: %d\n", flush_cnt);
    printf("Final flush probability: %.5f\n", (double) flush_cnt / hand_cnt);
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
