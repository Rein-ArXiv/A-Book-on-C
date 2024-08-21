/* Chapter 10 exercise 13 */

/* 리스트에서 특정 DATA 항목을 저장하고 있는 원소 바로 뒤에 한 원소를 삽입하는
 * 삽입 함수를 작성하여라.
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

void insert_after_data(LINK* head_ref, DATA find, DATA d)
{
    LINK node = (LINK) malloc(sizeof(ELEMENT));
    LINK* current = head_ref;

    strcpy(node -> d.name, d.name);
    node -> d.age = d.age;
    node -> d.weight = d.weight;
    
    while (*current != NULL){
        if (strcmp(((*current) -> d.name), find.name) == 0 &&
            (*current) -> d.age == find.age &&
            (*current) -> d.weight == find.weight){
            break;
        }

        current = &((*current) -> next);
    }

    if ((*current) == NULL){
    printf("Error: Not found data. Cannot insert after nonexistent data.\n");
        free(node);
        return;
    }

    node -> next = (*current) -> next;
    (*current) -> next = node;
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
    int size = 1;
    DATA d[1] = {
        {"Eve", 18, 80},
    };

    h = create_l(d, size);

    printf("Original Linked list:\n");
    print_list(h);
    putchar('\n');

    DATA find = {"Eve", 18, 80};
    DATA d2 = {"Lilith", 20, 40};

    insert_after_data(&h, find, d2);
    printf("Inserted Linked list:\n");
    print_list(h);

    return 0;
}
