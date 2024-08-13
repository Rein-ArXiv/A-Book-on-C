/* Chapter 7 exercise 20 */

/* (균형 잡힌 식사 프로그램) 5가지의 기본적인 음식 그룹들을 정의하기 위해 열거
 * 형을 사용하여라: 어류, 과일류, 곡류, 육류, 채소류. 각 음식 그룹에서부터 한 가
 * 지 음식을 선택하기 위해 난수 발생기를 사용하여라. 5개의 음식 그룹으로부터 한
 * 가지씩의 음식을 선택하여 메뉴를 출력하는 함수 meal()을 작성하여라. 20가지의
 * 메뉴를 출력하여라. 얼마나 다른 메뉴가 가능한가?
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    FISH,
    FRUIT,
    GRAIN,
    MEAT,
    VEGETABLE,
    NUM_FOOD_GROUPS // Number of foods groups
} FoodGroup;

const char* foodItems[NUM_FOOD_GROUPS][5] = {
    {"연어", "고등어", "참치", "광어", "대구"},     // FISH
    {"사과", "바나나", "딸기", "포도", "오렌지"},   // FRUIT
    {"쌀", "보리", "밀", "귀리", "옥수수"},       // GRAIN
    {"소고기", "돼지고기", "닭고기", "양고기", "오리고기"}, // MEAT
    {"시금치", "브로콜리", "당근", "양파", "감자"}   // VEGETABLE
};

void meal(void)
{
    srand(time(NULL));

    for (int i = 0; i < 20; i++){
        printf("Menu #%2d : ", i + 1);
        for (FoodGroup group = FISH; group < NUM_FOOD_GROUPS; group++){
            int randomIndex = rand() % 5;
            printf("%s\t", foodItems[group][randomIndex]);
        }
        printf("\n");
    }
}

int main(void)
{
    meal();
    return 0;
}