/* Chapter 10 exercise 6 */

/* 연습 문제 5번은 사이클을 구성하기 위해 사용되었다. 사이클은 다시 자기 자신을
 * 포인트하는 포인터 체인이다. 이것은 실행시간 오류로 찾아내기가 매우 어렵다.
 * 사이클을 검사하는 iscycle(head) 함수를 작성하여라. 이 함수는 사이클을 검출
 * 하면 1을, 그렇지 않다면 0을 리턴해야 한다. 힌트: 리스트의 첫 번째 원소의 주소
 * 를 저장하고, NULL을 만나거나 저장된 주소를 만날 때까지 계속 리스트 상을 이
 * 동하여라.
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

int is_cycle(LINK head)
{
    if (head == NULL) return 0;

    int cycle_check = 0;

    LINK current = head;
    while (current != NULL) {
        current = current -> next;
        
        if (current == head){
            cycle_check = 1;
            break;
        }
    }
    return cycle_check;
}

void print_list(LINK head)
{
    LINK current = head;
    while (current != NULL && current -> next != head) {
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

    printf("Original Linked list cyclical: ");

    int cycleic = is_cycle(h);

    if (cycleic == 1) printf("True\n");
    else printf("False\n");

    concatenate(h, h);
    printf("Concatenated Linked list cyclical: ");

    cycleic = is_cycle(h);

    if (cycleic == 1) printf("True\n");
    else printf("False\n");

    return 0;
}
