/* Chapter 10 exercise 3 */

/* 연습 문제 2번의 선형 리스트를 age 값으로 정렬하는 sort_age() 함수와 name
 * 에 따라 사전적 순서로 정렬하는 sort_name() 함수를 작성하여라.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[10];
    int age;
    int weight;
} DATA;

struct linked_list {
    DATA d;
    struct linked_list *next;
};

typedef struct linked_list ELEMENT;
typedef ELEMENT *LINK;

LINK create_l(DATA d[], int size)
{
    LINK head = NULL, tail;
    
    int i = 0;

    if (size != 0) {        // first element
        head = malloc(sizeof(ELEMENT));
        strcpy(head -> d.name, d[0].name);
        head -> d.age = d[0].age;
        head -> d.weight = d[0].weight;
        tail = head;

        for (i = 1; i < size; i++) {
            tail -> next = malloc(sizeof(ELEMENT));
            tail = tail -> next;
            strcpy(tail -> d.name, d[i].name);
            tail -> d.age = d[i].age;
            tail -> d.weight = d[i].weight;
        }

        tail -> next = NULL;
    }
    return head;
}

void print_list(LINK head)
{
    LINK current = head;
    while (current != NULL) {
        printf("Name: %s\tAge: %d\tWeight: %d\n", current -> d.name, current -> d.age, current -> d.weight);
        current = current -> next;
    }
}

int count_people(LINK head, int age, int weight)
{
    int count = 0;
    LINK current = head;
    while (current != NULL) {
        if (current -> d.age == age && current -> d.weight == weight){
            count++;
        }
        current = current -> next;
    }
    return count;
}

void sort_by_age(LINK head)
{
    
}

int main(void)
{
    LINK h;
    int size = 5;
    DATA d[5] = {
        {"Alice", 25, 50},
        {"Bob", 30, 70},
        {"Charlie", 35, 85},
        {"David", 30, 70},
        {"Eve", 25, 50}
    };

    h = create_l(d, size);

    print_list(h);

    int age = 30;
    int weight = 70;
    int count = count_people(h, age, weight);

    printf("Number of people with age %d and weight %d: %d\n", age, weight, count);
    return 0;
}
