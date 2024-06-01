/* Chapter 7 exercise 22 */

/* 연습 문제 21번의 함수에 의해 생성된 카드 패의 내용이 스트레이트, 플러시, 또
 * 는 풀 하우스인지를 검사하는 루틴들을 작성하여라. 스트레이트는 5장 카드의 점
 * 수 값들이 연속적인 순서로 되었을 때이며, 플러시는 5장의 카드가 모두 같은 무
 * 늬 값을 가질 때이고, 풀 하우스는 3장의 카드와 2장의 카드가 각각 같은 점수 값
 * 을 가질 때이다. 무작위로 패를 계속 만들고, 만든 패가 스트레이트, 플러시, 또는
 * 풀 하우스 중 하나일 때, 그 패가 몇 번째 패인가와 무슨 패인가를 출력하여라.
 * 이러한 동작을 세 가지 종류의 패가 모두 나올 때까지나 5000번의 패를 만들 때
 * 까지 계속하여라. 만일 후자의 경우로 인해 프로그램이 종료되었다면, 작성된 프
 * 로그램은 무엇인가 오류가 있는 것으로 보아야 한다. 그 이유를 알고 있는가?
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum suit {Heart, Clover, Diamond, Spade};

typedef struct {
    int score;
    enum suit suit;
} Card;

Card select_card(void)
{
    Card card;
    card.suit = rand() % 4;
    card.score = rand() % 13 + 1;
    return card;
}

void unique_cards_check(Card cards[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if ((cards[i].suit == cards[j].suit) && (cards[i].score == cards[j].score)){
                cards[i].suit = rand() % 4;
                cards[i].score = rand() % 13 + 1;

                i = 0;
                j = 0;
            }
        }
    }
}

void card_swap(Card *p, Card *q)
{
    Card tmp;

    tmp = *p;
    *p = *q;
    *q = tmp;
}

void card_sort(Card cards[], int n){
    int sorted, i, j;
    for(i = 0; i < n - 1; i++){
        sorted = 1;
        for(j = n - 1; j > i; j--){
            if (cards[j - 1].score > cards[j].score){
                card_swap(&cards[j - 1], &cards[j]);
                sorted = 0;
            }
        }
        if (sorted) {
            return;
        }
    }
}

int is_straight(const Card cards[], int n){
    int straight = 0, straight_count = 1;
    for (int i = 0; i < n - 1; i++){
        if ((cards[i].score + 1) == cards[i+1].score){
            straight_count++;
        }
    }

    if (straight_count >= 5){
        straight = 1;
    }
    return straight;
}

int is_flush(const Card cards[], int n){
    int flush = 0;
    int suit_count[4] = {0};
    for (int i = 0; i < n; i++){
        suit_count[(int) cards[i].suit]++;
    }
    for (int i = 0; i < 4; i++){
        if(suit_count[i] >= 5){
            flush = 1;
            break;
        }
    }
    return flush;
}

int is_fullhouse(const Card cards[], int n){
    int fullhouse = 0, triple = 0, pair = 0;
    int triple_num = -1, pair_num = -1;
    for (int i = 0; i < n - 2; i++){
        if ((cards[i].score == cards[i+1].score) && (cards[i+1].score == cards[i+2].score)){
            triple = 1;
            triple_num = cards[i].score;
            break;
        }
    }

    for (int i = 0; i < n - 1; i++){
        if (cards[i].score == triple_num){
            continue;
        }
        if (cards[i].score == cards[i+1].score){
            pair = 1;
            pair_num = cards[i].score;
            break;
        }
    }
    
    if (triple && pair){
        fullhouse = 1;
    }
    return fullhouse;
}

void print_cards(const Card cards[], int n) {
    for (int i = 0; i < n; i++) {
        const char *suits[] = {"Heart", "Clover", "Diamond", "Spade"};
        printf("Card %d: %d of %s\n", i + 1, cards[i].score, suits[cards[i].suit]);
    }
}


int main(void)
{
    srand(time(NULL));
    int n = 5;
    int straight_count = 0, flush_count = 0, fullhouse_count = 0;
    int t, i;
    Card cards[5];

    for (t=0; t<5000; t++){
        for(i=0; i<5; i++){
            cards[i] = select_card();
        }

        unique_cards_check(cards, n);
        card_sort(cards, n);

        if (is_straight(cards, n)){
            printf("Straight\n");
            print_cards(cards, n);
            straight_count++;
        }

        if (is_flush(cards, n)){
            printf("Flush\n");
            print_cards(cards, n);
            flush_count++;
        }

        if (is_fullhouse(cards, n)){
            printf("Fullhouse\n");
            print_cards(cards, n);
            fullhouse_count++;
        }

        if (straight_count && flush_count && fullhouse_count){
            break;
        }
    }
    printf("Test end. %d-th trial\n", t);
    printf("Straight: %d \t Flush: %d \t Fullhouse: %d\n", straight_count, flush_count, fullhouse_count);
    return 0;
}