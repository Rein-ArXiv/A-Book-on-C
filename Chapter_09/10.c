/* Chapter 9 exercise 10 */

/* 음식점을 기술할 수 있는 구조체를 작성하여라. 이 구조체는 음식점의 이름, 주소,
 * 평균가격, 음식의 형태 등을 나타내는 멤버들을 가져야 한다. 이 구조체를 이용하
 * 여 주어진 음식 형태를 취급하는 모든 음식점을 가격이 저렴한 순으로 출력하는
 * 프로그램을 작성하여라.
 */

#include <stdio.h>

typedef enum { meat, seafood, fruit, vegetable, grain, dairy, beverages } Foodtype;

typedef struct restaurant {
    char* name;
    char* address;
    float avg_cost;
    Foodtype foodtype;
} restaurant;

