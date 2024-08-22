/* Chapter 10 exercise 15 */

/* 이중 연결 선형 리스트의 원소는 다음과 같이 정의된다.

    typedef struct dllist {
        DATA d;
        struct dllist *prev;
        struct dllist *next;
    } ELEMENT;

 * 이것에는 멤버가 하나 더 추가되었지만, 리스트상의 이동을 더 쉽게 해준다.
 * 삽입과 제거를 수행하는 반복적 루틴을 작성하여라.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[10];
    int age;
    int weight;
} DATA;

struct dllist {
    DATA d;
    struct dllist *prev;
    struct dllist *next;
};

typedef struct dllist ELEMENT;
typedef ELEMENT *DLINK;

DLINK create_dl(DATA d[], int size)
{
    DLINK head = NULL, tail = NULL;

    int i = 0;

    if (size != 0) {        // first element
        head = (DLINK) malloc(sizeof(ELEMENT));
        strcpy(head -> d.name, d[0].name);
        head -> d.age = d[0].age;
        head -> d.weight = d[0].weight;
        head -> prev = NULL;
        tail = head;

        for (i = 1; i < size; i++) {
            tail -> next = (DLINK) malloc(sizeof(ELEMENT));
            tail -> next -> prev = tail;
            tail = tail -> next;
            strcpy(tail -> d.name, d[i].name);
            tail -> d.age = d[i].age;
            tail -> d.weight = d[i].weight;
        }
        tail -> next = NULL;
    }
    return head;
}

void insert(DLINK* head_ref, DATA d, int index)
{
    DLINK node = (DLINK) malloc(sizeof(ELEMENT));
    strcpy(node->d.name, d.name);
    node->d.age = d.age;
    node->d.weight = d.weight;

    int n = 0;

    if (index == 0){
        node -> next = *head_ref;
        node -> prev = NULL;

        if ((*head_ref) != NULL){
            (*head_ref) -> prev = node;
        }
        *head_ref = node;
        return;
    }

    DLINK current = *head_ref;
    while (current -> next != NULL && n < index) {
        current = ((current)->next);
        n++;
    }

    if (current -> next == NULL && n < index){  // Insert on last of list
        current -> next = node;
        node -> prev = current;
        node -> next = NULL;
    }
    else {
        node->prev = current -> prev;
        node->next = current;
        
        if (current -> prev != NULL){
            current -> prev -> next = node;
        }
        current -> prev = node;
    }
}

DATA delete(DLINK* head_ref, int index){
    DATA d = {"NULL", -1, -1};
    DLINK current = (*head_ref);

    if (*head_ref == NULL) {
        printf("Linked list is empty. Nothing to remove.\n");
        return d;
    }

    if (index == 0){
        (*head_ref) = current -> next;

        if (*head_ref != NULL){
            (*head_ref) -> prev = NULL;
        }

        strcpy(d.name, current -> d.name);
        d.age = current -> d.age;
        d.weight = current -> d.weight;
        free(current);
        return d;
    }

    int n = 0;
    while (current != NULL && n < index){
        current = current -> next;
        n++;
    }

    if (current == NULL){
        printf("Index is out of bounds. Node not removed.\n");
        return d;
    }

    if (current -> next != NULL){
        current -> next -> prev = current -> prev;
    }

    if (current -> prev != NULL){
        current -> prev -> next = current -> next;
    }

    strcpy(d.name, current -> d.name);
    d.age = current -> d.age;
    d.weight = current -> d.weight;
    free (current);
    return d;
}

void print_list(DLINK head)
{
    DLINK current = head;
    DLINK tail = current;
    printf("From head to tail\n");
    while (current != NULL){
        printf("Name: %s\tAge: %d\tWeight: %d\n",
                current -> d.name,
                current -> d.age,
                current -> d.weight);

        tail = current;
        current = current -> next;
    }
}

int main(void)
{
    DLINK h;
    int size = 5;
    DATA d[5] = {
        {"Alice", 25, 50},
        {"David", 30, 70},
        {"Bob", 30, 70},
        {"Eve", 25, 50},
        {"Charlie", 35, 85},
    };

    h = create_dl(d, size);
    print_list(h);
    putchar('\n');

    // 테스트 1: 리스트의 맨 앞에 삽입
    DATA d1 = {"Zara", 28, 60};
    insert(&h, d1, 0);
    printf("After inserting 'Zara' at the beginning:\n");
    print_list(h);
    putchar('\n');

    // 테스트 2: 리스트의 중간에 삽입 (index 3)
    DATA d2 = {"Liam", 22, 65};
    insert(&h, d2, 3);
    printf("After inserting 'Liam' at index 3:\n");
    print_list(h);
    putchar('\n');

    // 테스트 3: 리스트의 끝에 삽입 (index가 리스트의 길이보다 큼)
    DATA d3 = {"Mia", 27, 55};
    insert(&h, d3, 100);  // 큰 index를 주면 리스트의 끝에 삽입
    printf("After inserting 'Mia' at the end:\n");
    print_list(h);
    putchar('\n');

    // 테스트 4: 리스트의 맨 앞에서 제거
    DATA removed_data = delete(&h, 0);
    printf("After removing the head ('%s'):\n", removed_data.name);
    print_list(h);
    putchar('\n');

    // 테스트 5: 리스트의 중간에서 제거 (index 2)
    removed_data = delete(&h, 2);
    printf("After removing node at index 2 ('%s'):\n", removed_data.name);
    print_list(h);
    putchar('\n');

    // 테스트 6: 리스트의 끝에서 제거 (index가 리스트의 길이보다 큼)
    removed_data = delete(&h, 100);  // 큰 index를 주면 리스트의 끝에서 제거
    printf("After removing the last node ('%s'):\n", removed_data.name);
    print_list(h);
    putchar('\n');

    return 0;
}
