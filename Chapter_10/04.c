/* Chapter 10 exercise 4 */

/* 연습 문제 3번의 두 정렬 함수를 결합하여 대부분의 코드를 공유하는 함수를 만
 * 들어라. 이것은 두 원소의 값을 받아들여 어느 원소가 큰지에 따라 0이나 1을 리
 * 턴하는 compare() 함수를 정의하면 쉽게 작성할 수 있다. 선형 리스트 정렬 함
 * 수에서 이 함수를 매개변수로 사용하여라.
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
        head = (LINK) malloc(sizeof(ELEMENT));
        strcpy(head -> d.name, d[0].name);
        head -> d.age = d[0].age;
        head -> d.weight = d[0].weight;
        tail = head;

        for (i = 1; i < size; i++) {
            tail -> next = (LINK) malloc(sizeof(ELEMENT));
            tail = tail -> next;
            strcpy(tail -> d.name, d[i].name);
            tail -> d.age = d[i].age;
            tail -> d.weight = d[i].weight;
        }

        tail -> next = NULL;
    }
    return head;
}

LINK get_tail(LINK cur) {
    while (cur != NULL && cur -> next != NULL) {
        cur = cur -> next;
    }
    return cur;
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

int compare_by_age(DATA d1, DATA d2)
{
    return d1.age - d2.age;
}

int compare_by_name(DATA d1, DATA d2)
{
    return strcmp(d1.name, d2.name);
}

void bubble_swap(LINK ptr1, LINK ptr2)
{
    DATA tmp = ptr1 -> d;
    ptr1 -> d = ptr2 -> d;
    ptr2 -> d = tmp;
}

void bubble_sort(LINK* head, int (*compare)(DATA, DATA))
{
    if (*head == NULL) return;

    LINK i;
    int swapped;

    do {
        swapped = 0;
        i = *head;
        while (i -> next != NULL){
            if (compare(i -> d, i -> next -> d) > 0){
                bubble_swap(i, i -> next);
                swapped = 1;
            }
            i = i -> next;
        }
    } while (swapped);
}

// Bubble sort를 사용해 정렬
void sort_by_age(LINK* head)
{
    bubble_sort(head, compare_by_age);
}

void sort_by_name(LINK* head)
{
    bubble_sort(head, compare_by_name);
}

int main(void)
{
    LINK h;
    int size = 5;
    DATA d[5] = {
        {"Alice", 25, 50},
        {"David", 30, 70},
        {"Bob", 30, 70},
        {"Eve", 25, 50},
        {"Charlie", 35, 85},
    };

    h = create_l(d, size);

    printf("Original Linked list:\n");
    print_list(h);
    putchar('\n');

    printf("Sorted by age:\n");
    sort_by_age(&h);
    print_list(h);
    putchar('\n');

    printf("Sorted by name:\n");
    sort_by_name(&h);
    print_list(h);

    return 0;
}
