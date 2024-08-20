/* Chapter 10 exercise 5 */

/* concatenate(a, a)로 만들어지는 리스트를 그려보아라. 이때, a는 두 개의 원소
 * 를 갖는 리스트를 포인트한다고 가정한다. 만일 a가 포인트하고 있는 결과 리스트
 * 가 print_list(a)에 전달된다면 어떤 일이 발생하는가?
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

void concatenate(LINK a, LINK b)
{
    if (a == NULL){
        a = b;
        return;
    }

    LINK node = a;
    while (node -> next != NULL){
        node = node -> next;
    }
    node -> next = b;
}

void print_list(LINK head)
{
    LINK current = head;
    while (current != NULL) {
        printf("Name: %s\tAge: %d\tWeight: %d\n", current -> d.name, current -> d.age, current -> d.weight);
        current = current -> next;
    }
}


int main(void)
{
    LINK h;
    int size = 2;
    DATA d[2] = {
        {"Eve", 18, 80},
        {"Lilith", 20, 40},
    };

    h = create_l(d, size);

    printf("Original Linked list:\n");
    print_list(h);
    putchar('\n');

    concatenate(h, h);
    printf("Concatenated Linked list:\n");
    print_list(h);

    return 0;
}
