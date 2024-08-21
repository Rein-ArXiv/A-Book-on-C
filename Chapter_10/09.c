/* Chapter 10 exercise 9 */

/* 두 리스트 a와 b를 결합하여 복사한 리스트를 리턴하는 copy_cat(a, b) 함수를
 * 작성하여라. 단 원래의 리스트 a와 b는 변경되지 말아야 한다.
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

    if (size != 0){
        head = (LINK) malloc(sizeof(ELEMENT));
        strcpy(head -> d.name, d[0].name);
        head -> d.age = d[0].age;
        head -> d.weight = d[0].weight;
        tail = head;
    }

    for (int i = 1; i < size; i++){
        tail -> next = (LINK) malloc(sizeof(ELEMENT));
        tail = tail -> next;
        strcpy(tail -> d.name, d[i].name);
        tail -> d.age = d[i].age;
        tail -> d.weight = d[i].weight;
    }
    tail -> next = NULL;

    return head;
}

LINK copy_cat(LINK a, LINK b)
{
    LINK a_head = a, b_head = b, c;
    LINK head = NULL, tail;
    DATA *d;
    int a_size = 0, b_size = 0, c_size;
    while (a != NULL){
        a_size++;
        a = a -> next;
    }
    while (b != NULL){
        b_size++;
        b = b -> next;
    }
    
    c_size = a_size + b_size;

    d = (DATA *) malloc(c_size * sizeof(DATA));

    if (d == NULL) {
        printf("Error: Memory allocation failed in copy_cat.\n");
        return NULL;
    };

    a = a_head;
    b = b_head;

    for (int i = 0; i < a_size; i++){
        strcpy(d[i].name, a -> d.name);
        d[i].age = a -> d.age;
        d[i].weight = a -> d.weight;
        a = a -> next;
    }

    for (int i = a_size; i < c_size; i++){
        strcpy(d[i].name, b -> d.name);
        d[i].age = b -> d.age;
        d[i].weight = b -> d.weight;
        b = b -> next;
    }

    c = create_l(d, c_size);
    free(d);
    return c;
}

LINK concatenate(LINK a, LINK b)
{
    if (a == NULL){
        a = b;
        return a;
    }

    if (a == b){
        printf("Error: Trying to concatenate the same list! Cancel concatenate.\n");
        return a;
    }

    LINK node = a;
    while (node -> next != NULL){
        node = node -> next;
    }
    node -> next = b;
    return a;
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
    LINK h, h2, c;
    int size = 2;
    DATA d[2] = {
        {"Eve", 18, 80},
        {"Lilith", 20, 40},
    };
    DATA d2[2] = {
        {"Adam", 30, 75},
        {"Steve", 25, 60},
    };

    h = create_l(d, size);
    h2 = create_l(d2, size);

    printf("Original Linked list 1:\n");
    print_list(h);
    putchar('\n');

    printf("Original Linked list 2:\n");
    print_list(h2);
    putchar('\n');

    c = copy_cat(h, h2);
    printf("Concatenated Linked list (copy):\n");
    print_list(c);

    free(h);
    free(h2);
    free(c);

    return 0;
}