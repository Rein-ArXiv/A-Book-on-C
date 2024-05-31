/* Chapter 7 exercise 21 */

/* 한 벌의 카드에서 임의로 5장의 카드를 선택하는 함수를 작성하여라. 작성된 함수
 * 는 선택한 모든 카드가 유일한지를 검사해야 한다. 각 카드는 점수와 무늬가 있
 * 다. 7과 하트가 그려진 카드는 점수 값이 7이고, 무늬 값은 하트이다. 에이스에 대
 * 한 점수는 1이고, 듀스는 2, ..., 그리고 킹은 13이다. 작성하는 함수에서 점수와 무
 * 늬의 값을 표현하기 위해 열거형을 사용하여라. 그리고, 선택된 카드를 출력하는
 * 다른 함수도 작성하여라.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum suit = {Heart, Clover, Diamond, Spade};

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

void select_card(Card cards[], int n){
    
    
    for (int i = 0; i < n; i++){
        int unique = 0;
        while (!unique){
            unique = 1;
        }
    }
}

int main(void)
{

}