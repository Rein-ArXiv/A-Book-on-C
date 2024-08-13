/* Chapter 9 exercise 17 */

/* (고급 수준) 현재 포커 패의 값을 리턴하는 hand_value() 함수를 작성하여라. 가
 * 장 좋은 패는 스트레이트 플러시이고, 가장 나쁜 패는 쌍이 없는 경우이다. 두 패
 * 중에서 어느 패가 좋은지를 비교하는 다른 함수도 작성해 보아라.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NDEALS 5    // 플레이 횟수
#define NPLAYERS 6  // 플레이어 수

typedef enum {clubs, diamonds, hearts, spades} cdhs;

typedef struct {
    int pips;
    cdhs suit;
} card;

typedef enum {
    HIGH_CARD,
    ONE_PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH,
    ROYAL_FLUSH
} hand_rank;

typedef struct {
    hand_rank rank;
    int high_card;
} hand_value;

card assign_values(int pips, cdhs suit);
void prn_card_values(card *c_ptr);
void prn_hand_values(card *hand);
void play_poker(card deck[52]);
void shuffle(card deck[52]);
void swap(card *p, card *q);
void deal_the_cards(card deck[52], card hand[NPLAYERS][5]);
int is_flush(card h[5]);
int is_straight(card h[5]);
int is_fullhouse(card h[5]);
int is_royal_flush(card h[5]);
int is_straight_flush(card h[5]);
int is_four_of_a_kind(card h[5]);
int is_three_of_a_kind(card h[5]);
int is_two_pair(card h[5]);
int is_one_pair(card h[5]);
int card_compare(const void *a, const void *b);
void card_sort(card *hand, int count);
hand_value evaluate_hand(card hand[5]);
int compare_hands(const void *a, const void *b);

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
    for (i = 0; i < 52; ++i)           // print out the deck
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

    if (pips == 14){
        pips = 1;
    }

    printf("card: %2d of %s\n", pips, suit_name);
}

void prn_hand_values(card *hand)
{
    int count = 5;
    for (int i = 0; i < count; i++){
        prn_card_values(&hand[i]);
    }
}

void play_poker(card deck[52])
{
    int i, j;
    card hand[NPLAYERS][5];  // 각 플레이어에게 5장의 카드

    srand(time(NULL));

    for (i = 0; i < NDEALS; ++i) {
        printf("########## %d-th Game ########\n\n", i);
        shuffle(deck);
        deal_the_cards(deck, hand);

        hand_value hand_values[NPLAYERS];

        for (j = 0; j < NPLAYERS; j++) {
            card_sort(hand[j], 5);
            hand_values[j] = evaluate_hand(hand[j]);
        }

        qsort(hand_values, NPLAYERS, sizeof(hand_value), compare_hands);

        for (j = 0; j < NPLAYERS; j++) {
            printf("Player %d:\n", j + 1);
            prn_hand_values(hand[j]);
            printf("Hand rank: %d, High card: %d\n\n", hand_values[j].rank, hand_values[j].high_card);
        }
        printf("\n\n");
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

int card_compare(const void *a, const void *b)
{
    card *cardA = (card *)a;
    card *cardB = (card *)b;

    if (cardA->pips != cardB->pips) {
        return (cardB->pips) - (cardA->pips); // descending order
    } else {
        return (int)((cardA->suit) - (cardB->suit));
    }
}

void card_sort(card *hand, int count)
{
    qsort(hand, count, sizeof(card), card_compare);

    while (hand[0].pips == 1) { // Ace
        hand[0].pips = 14;
        qsort(hand, count, sizeof(card), card_compare);
    }
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
    int i;
    for (i = 1; i < 5; ++i)
        if (h[i].pips != h[i - 1].pips - 1)
            return 0;
    return 1;
}

int is_fullhouse(card h[5])
{
    int pips[15] = {0};
    for (int i = 0; i < 5; ++i)
        pips[h[i].pips]++;
    int three = 0, two = 0;
    for (int i = 1; i <= 14; ++i) {
        if (pips[i] == 3) three = 1;
        if (pips[i] == 2) two = 1;
    }
    return three && two;
}

int is_royal_flush(card h[5])
{
    return is_straight_flush(h) && h[4].pips == 10;
}

int is_straight_flush(card h[5])
{
    return is_flush(h) && is_straight(h);
}

int is_four_of_a_kind(card h[5])
{
    int pips[15] = {0};
    for (int i = 0; i < 5; ++i)
        pips[h[i].pips]++;
    for (int i = 1; i <= 14; ++i)
        if (pips[i] == 4)
            return 1;
    return 0;
}

int is_three_of_a_kind(card h[5])
{
    int pips[15] = {0};
    for (int i = 0; i < 5; ++i)
        pips[h[i].pips]++;
    for (int i = 1; i <= 14; ++i)
        if (pips[i] == 3)
            return 1;
    return 0;
}

int is_two_pair(card h[5])
{
    int pips[15] = {0};
    for (int i = 0; i < 5; ++i)
        pips[h[i].pips]++;
    int pairs = 0;
    for (int i = 1; i <= 14; ++i)
        if (pips[i] == 2)
            pairs++;
    return pairs == 2;
}

int is_one_pair(card h[5])
{
    int pips[15] = {0};
    for (int i = 0; i < 5; ++i)
        pips[h[i].pips]++;
    for (int i = 1; i <= 14; ++i)
        if (pips[i] == 2)
            return 1;
    return 0;
}

hand_value evaluate_hand(card hand[5])
{
    hand_value value;
    card_sort(hand, 5);

    if (is_royal_flush(hand)) {
        value.rank = ROYAL_FLUSH;
        value.high_card = hand[0].pips;
    } else if (is_straight_flush(hand)) {
        value.rank = STRAIGHT_FLUSH;
        value.high_card = hand[0].pips;
    } else if (is_four_of_a_kind(hand)) {
        value.rank = FOUR_OF_A_KIND;
        value.high_card = hand[0].pips;
    } else if (is_fullhouse(hand)) {
        value.rank = FULL_HOUSE;
        value.high_card = hand[0].pips;
    } else if (is_flush(hand)) {
        value.rank = FLUSH;
        value.high_card = hand[0].pips;
    } else if (is_straight(hand)) {
        value.rank = STRAIGHT;
        value.high_card = hand[0].pips;
    } else if (is_three_of_a_kind(hand)) {
        value.rank = THREE_OF_A_KIND;
        value.high_card = hand[0].pips;
    } else if (is_two_pair(hand)) {
        value.rank = TWO_PAIR;
        value.high_card = hand[0].pips;
    } else if (is_one_pair(hand)) {
        value.rank = ONE_PAIR;
        value.high_card = hand[0].pips;
    } else {
        value.rank = HIGH_CARD;
        value.high_card = hand[0].pips;
    }
    return value;
}

int compare_hands(const void *a, const void *b)
{
    hand_value *handA = (hand_value *)a;
    hand_value *handB = (hand_value *)b;

    if (handA->rank != handB->rank)
        return handB->rank - handA->rank; // descending order
    else
        return handB->high_card - handA->high_card; // descending order
}
