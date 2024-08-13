/* Chapter 9 exercise 10 */

/* 음식점을 기술할 수 있는 구조체를 작성하여라. 이 구조체는 음식점의 이름, 주소,
 * 평균가격, 음식의 형태 등을 나타내는 멤버들을 가져야 한다. 이 구조체를 이용하
 * 여 주어진 음식 형태를 취급하는 모든 음식점을 가격이 저렴한 순으로 출력하는
 * 프로그램을 작성하여라.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { meat, seafood, fruit, vegetable, grain, dairy, beverages } Foodtype;

typedef struct restaurant {
    char name[50];
    char address[150];
    double avg_price;
    Foodtype foodtype;
} restaurant;

void initialize_restaurants(restaurant *restaurants, int *count)
{
    *count = 5;
    strcpy(restaurants[0].name, "Steak House");
    strcpy(restaurants[0].address, "123 Main st");
    restaurants[0].avg_price = 25.00;
    restaurants[0].foodtype = meat;

    strcpy(restaurants[1].name, "Seafood Delight");
    strcpy(restaurants[1].address, "456 Ocean Ave");
    restaurants[1].avg_price = 30.00;
    restaurants[1].foodtype = seafood;

    strcpy(restaurants[2].name, "Fruit Paradise");
    strcpy(restaurants[2].address, "789 Orchard Rd");
    restaurants[2].avg_price = 15.00;
    restaurants[2].foodtype = fruit;

    strcpy(restaurants[3].name, "Green Garden");
    strcpy(restaurants[3].address, "101 Veggie Ln");
    restaurants[3].avg_price = 20.00;
    restaurants[3].foodtype = vegetable;

    strcpy(restaurants[4].name, "Grain & Dairy");
    strcpy(restaurants[4].address, "202 Farm st");
    restaurants[4].avg_price = 10.00;
    restaurants[4].foodtype = grain;
}

int compare_price(const void *a, const void *b)
{
    restaurant *restaurantA = (restaurant *)a;
    restaurant *restaurantB = (restaurant *)b;

    if (restaurantA -> avg_price < restaurantB -> avg_price)
        return -1;

    if (restaurantA -> avg_price > restaurantB -> avg_price)
        return 1;
    return 0;
}

void print_restaurants_by_type(restaurant *restaurants, int count, Foodtype type)
{
    restaurant *filtered_restaurants = malloc(count * sizeof(restaurant));
    
    int filtered_count = 0;

    for (int i = 0; i < count; i++){
        if (restaurants[i].foodtype == type){
            filtered_restaurants[filtered_count++] = restaurants[i];
        }
    }

    qsort(filtered_restaurants, filtered_count, sizeof(restaurant), compare_price);

    for (int i = 0; i < filtered_count; i++) {
        printf("Name: %s, Address: %s, Avg Price: $%.2f\n",
                filtered_restaurants[i].name,
                filtered_restaurants[i].address,
                filtered_restaurants[i].avg_price);
    }

    free(filtered_restaurants);
}

int main(void)
{
    restaurant restaurants[10];

    int count;

    initialize_restaurants(restaurants, &count);

    printf("Seafood Restaurants sorted by price:\n");
    print_restaurants_by_type(restaurants, count, seafood);

    return 0;
}
