/* Chapter 10 exercise 14 */

/* 연습 문제 11, 12, 13번을 일반화하여라. 리스트의 n 번째 위치에 한 원소를 삽입
 * 하는 삽입 함수를 작성하여라. 여기서 n이 0이면, 리스트의 헤드 위치에 원소를
 * 삽입해야 한다. 그리고, n이 리스트의 길이보다 크다면, 리스트의 끝에 원소를 삽
 * 입해야 한다.
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

void insert(LINK* head_ref, DATA d, int index)
{
    LINK node = (LINK) malloc(sizeof(ELEMENT));
    strcpy(node->d.name, d.name);
    node->d.age = d.age;
    node->d.weight = d.weight;

    LINK* current = head_ref;
    int n = 0;

    while (*current != NULL && n < index) {
        current = &((*current)->next);
        n++;
    }

    node->next = *current;
    *current = node;
}

void insert_head(LINK* head_ref, DATA d)
{
    LINK new_head = (LINK) malloc(sizeof(ELEMENT));
    new_head -> next = *head_ref;
    strcpy(new_head -> d.name, d.name);
    new_head -> d.age = d.age;
    new_head -> d.weight = d.weight;

    *head_ref = new_head;
}

void insert_tail(LINK* head_ref, DATA d)
{
    LINK new_tail = (LINK) malloc(sizeof(ELEMENT));
    
    LINK tail = *head_ref;
    while (tail -> next != NULL){
        tail = tail -> next;
    }
    strcpy(new_tail -> d.name, d.name);
    new_tail -> d.age = d.age;
    new_tail -> d.weight = d.weight;

    tail -> next = new_tail;
}

void print_list(LINK head)
{
    LINK current = head;
    while (current != NULL) {
        printf("Name: %s\tAge: %d\tWeight: %d\n", current -> d.name, current -> d.age, current -> d.weight);
        current = current -> next;
        
        if (current == head) break; // if cycleic break
    }
}

int main(void)
{
    LINK h;
    int size = 2;
    DATA d[2] = {
        {"Eve", 18, 80},
        {"Lilith", 20, 40}
    };

    h = create_l(d, size);

    printf("Original Linked list:\n");
    print_list(h);
    putchar('\n');

    DATA d2 = {"Alice", 10, 25};

    insert(&h, d2, 2);
    printf("Inserted on Index 0 Linked list:\n");
    print_list(h);

    return 0;
}
