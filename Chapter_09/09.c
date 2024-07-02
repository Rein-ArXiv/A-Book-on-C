/* Chapter 9 exercise 9 */

/* 균형 있는 식단을 작성하는 프로그램을 작성하여라. 먼저 음식의 이름, 각 음식의
 * 칼로리, 그리고 고기, 과일과 같은 음식 형태, 비용 등을 포함하는 구조체를 정의
 * 하여라. 그리고, 각 음식은 구조체의 배열에 저장하여라. 프로그램이 생성하는 식
 * 단은 4가지 다른 음식 형태를 포함하고, 요청된 칼로리를 넘지 않으며, 제한한 가
 * 격을 만족해야 한다. 그리고 가장 많은 수의 다른 메뉴를 구성할 수 있도록 작성
 * 되어야 한다.
 */

#include <stdio.h>

#define MAX_FOODS 10

typedef enum { meat, seafood, fruit, vegetable, grain, dairy, beverages } Foodtype;

typedef struct food{
    char* name;
    Foodtype foodtype;
    double cost;
    int calories;
} food;

int main(void)
{
    food diet[MAX_FOODS] = {
        {"Chicken Breast", meat, 5.50, 165},
        {"Salmon", seafood, 7.20, 208},
        {"Apple", fruit, 1.00, 52},
        {"Broccoli", vegetable, 2.50, 55},
        {"Rice", grain, 0.80, 130},
        {"Milk", dairy, 1.50, 103},
        {"Orange Juice", beverages, 2.00, 112},
        {"Banana", fruit, 1.20, 89},
        {"Carrot", vegetable, 1.00, 41},
        {"Cheese", dairy, 3.00, 113}
    };

    double max_cost;
    int max_calories;

    printf("Input max cost: ");
    scanf("%lf", &max_cost);

    printf("Input max calories: ");
    scanf("%d", &max_calories);

    food selected_diet[MAX_FOODS];
    int selected_count = 0;
    double total_cost = 0.0;
    int total_calories = 0;

    for (int i = 0; i < MAX_FOODS; i++) {
        if (total_cost + diet[i].cost <= max_cost && total_calories + diet[i].calories <= max_calories) {
            selected_diet[selected_count++] = diet[i];
            total_cost += diet[i].cost;
            total_calories += diet[i].calories;
        }
    }

    printf("Selected Diet:\n");
    for (int i = 0; i < selected_count; i++) {
        printf("Name: %s, Type: %d, Cost: $%.2f, Calories: %d\n", selected_diet[i].name, selected_diet[i].foodtype, selected_diet[i].cost, selected_diet[i].calories);
    }
    printf("Total Cost: $%.2f, Total Calories: %d\n", total_cost, total_calories);

    return 0;
}