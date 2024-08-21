/* Chapter 10 exercise 8 */

/* concatenate() 함수를 수정하여 생성된 리스트의 헤드 주소를 리턴하도록 하여
 * 라. 그리고 첫 번째 리스트가 NULL이면, 두 번째 리스트를 리턴해야 한다. 또한,
 * 두 리스트가 같은지를 검사하여라. 만일 같다면, 경고 메시지를 출력해야 한다.
 * (연습 문제 5번과 6번을 참고하여라.)
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

    h = concatenate(h, h);
    printf("Concatenated Linked list:\n");
    print_list(h);

    return 0;
}
