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

void bubble_swap(LINK ptr1, LINK ptr2)
{
    DATA tmp = ptr1 -> d;
    ptr1 -> d = ptr2 -> d;
    ptr2 -> d = tmp;
}

// Bubble sort를 사용해 정렬
void sort_by_age(LINK* head)
{
    if (*head == NULL) return;

    LINK i;
    int swapped;

    do {
        swapped = 0;
        i = *head;
        while (i -> next != NULL){
            if (i -> d.age > i -> next -> d.age){
                bubble_swap(i, i -> next);
                swapped = 1;
            }
            i = i -> next;
        }
    } while (swapped);
}

void quick_swap(LINK* curr, LINK* tail)
{
    LINK tmp = (*curr) -> next;
    (*curr) -> next = NULL;
    (*tail) -> next = *curr;
    *tail = *curr; 
    *curr = tmp;
}

LINK partition(LINK low, LINK high, LINK* new_low, LINK* new_high)
{
    char* pivot = high -> d.name;
    LINK prev = NULL, curr = low, tail = high;

    while (curr != high){
        // pivot 보다 작은 node를 왼쪽에 위치시킨다.
        if (strcmp(curr -> d.name, pivot) < 0) {
            if ((*new_low) == NULL) {
                (*new_low) = curr;
            }
            prev = curr;
            curr = curr -> next;
        }
        // pivot 보다 큰 node를 오른쪽에 위치시킨다.
        else {
            if (prev) {
                prev -> next = curr -> next;
            }
            quick_swap(&curr, &tail);
        }
    }

    if ((*new_low) == NULL) {
        (*new_low) = high;
    }

    (*new_high) = tail;
    return high;
}

LINK quick_sort(LINK low, LINK high)
{
    if (!low || low == high) {
        return low;
    }

    LINK new_low = NULL, new_high = NULL;
    LINK pivot = partition(low, high, &new_low, &new_high);

    if (new_low != pivot) {
        LINK tmp = new_low;
        while (tmp -> next != pivot) {
            tmp = tmp -> next;
        }
        tmp -> next = NULL;

        new_low = quick_sort(new_low, tmp);
        tmp = get_tail(new_low);
        tmp -> next = pivot;
    }

    pivot -> next = quick_sort(pivot -> next, new_high);
    return new_low;
}


void sort_by_name(LINK* head)
{
    if ((*head) == NULL) return;

    LINK h = *head;
    LINK t = get_tail(h);
    *head = quick_sort(h, t);
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
