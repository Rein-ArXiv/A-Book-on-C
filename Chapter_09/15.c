/* Chapter 9 exercise 15 */

/* poker 프로그램에 포커 패가 풀 하우스인지를 검사하는 is_fullhouse() 함수
 * 추가하여라. is_fullhouse() 함수는 풀 하우스가 나올 때마다, 확률을 계산하여
 * 출력해야 한다. 풀 하우스는 플러시보다 높으므로, 풀 하우스가 나올 확률은 플러
 * 시가 나올 확률보다 낮을 것이다. 수정된 poker 프로그램의 결과는 어떤지 설명
 * 하여라.
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
int is_straight(card h[5]);
int is_fullhouse(card h[5]);

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

    printf("Deck check:\n");
    for (i = 0; i < 52; ++i)           // print out the hearts
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
    int flush_cnt = 0, straight_cnt = 0, fullhouse_cnt = 0, hand_cnt = 0;
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
                printf("          Hand number: %d\n", hand_cnt);
                printf("         Flush number: %d\n", flush_cnt);
                printf("    Flush probability: %.5f\n\n", (double) flush_cnt / hand_cnt);
            }

            if (is_straight(hand[j])) {
                ++straight_cnt;
                printf("          Hand number: %d\n", hand_cnt);
                printf("      Straight number: %d\n", straight_cnt);
                printf(" Straight probability: %.5f\n\n", (double) straight_cnt / hand_cnt);
            }

            if (is_fullhouse(hand[j])) {
                ++fullhouse_cnt;
                printf("          Hand number: %d\n", hand_cnt);
                printf("     Fullhouse number: %d\n", fullhouse_cnt);
                printf("Fullhouse probability: %.5f\n\n", (double) fullhouse_cnt / hand_cnt);
            }
        }
    }

    printf("Total hands dealt:              %d\n", hand_cnt);

    printf("Total flushes:                  %d\n", flush_cnt);
    printf("Final flush probability:        %.5f\n\n", (double) flush_cnt / hand_cnt);

    printf("Total straight:                 %d\n", straight_cnt);
    printf("Final straight probability:     %.5f\n\n", (double) straight_cnt / hand_cnt);

    printf("Total fullhouse:                %d\n", fullhouse_cnt);
    printf("Final fullhouse probability:    %.5f\n\n", (double) fullhouse_cnt / hand_cnt);
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

int is_straight(card h[5])
{
    int i, j, temp;
    int pips[5];
    int straight = 0;
    for (i = 0; i < 5; ++i){
        pips[i] = h[i].pips;
    }

    for (i = 0; i < 4; ++i){
        for (j = 0; j < 4 - i; ++j){
            if (pips[j] > pips[j + 1]){
                temp = pips[j];
                pips[j] = pips[j + 1];
                pips[j + 1] = temp;
            }
        }
    }

    for (i = 1; i < 5; ++i){
        if (pips[i] != pips[i - 1] + 1){
            break;
        }
    }

    if (i == 5){
        straight = 1;
    }
    else{
        // 10, J, Q, K, A straight
        if (pips[0] == 1 && pips[1] == 10 && pips[2] == 11 && pips[3] == 12 && pips[4] == 13){
            straight = 1;
        }
    }
    return straight;
}

int is_fullhouse(card h[5])
{
    int i, j, temp;
    int pips[5];
    int fullhouse = 0;

    for (i = 0; i < 5; ++i){
        pips[i] = h[i].pips;
    }

    for (i = 0; i < 4; ++i){
        for (j = 0; j < 4 - i; ++j){
            if (pips[j] > pips[j + 1]){
                temp = pips[j];
                pips[j] = pips[j + 1];
                pips[j + 1] = temp;
            }
        }
    }

    
    if ((pips[0] == pips[1] && pips[1] == pips[2]) && (pips[3] == pips[4])){
        fullhouse = 1;
    }

    if ((pips[0] == pips[1]) && (pips[2] == pips[3] && pips[3] == pips[4])){
        fullhouse = 1;
    }

    return fullhouse;
}