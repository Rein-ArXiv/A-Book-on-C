/* Chapter 10 exercise 16 */

/* 이중 연결 리스트에서 중복 원소를 제거하는 del_dupl() 루틴을 작성하여라.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 100

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

typedef struct node {
    DATA data;
    struct node *next;
} HashNode;

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

unsigned int hash(DATA d)
{
    unsigned int hashValue = 0;
    for (int i = 0; i < strlen(d.name); i++) {
        hashValue = hashValue * 31 + d.name[i];
    }
    return hashValue % TABLE_SIZE;
}

bool compare_data(DATA d1, DATA d2)
{
    bool name_check = (strcmp(d1.name, d2.name) == 0);
    bool age_check = (d1.age == d2.age);
    bool weight_check = (d1.weight == d2.weight);
    bool all_check = (name_check && age_check && weight_check);
    return all_check;
}

bool find(HashNode* table[], DATA d)
{
    unsigned int hashValue = hash(d);
    HashNode* node = table[hashValue];

    while (node != NULL){
        if (compare_data(node -> data, d)) {
            return true;
        }
        node = node -> next;
    }
    return false;
}

void insert_hash(HashNode* table[], DATA d)
{
    unsigned int hashValue = hash(d);
    HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
    new_node -> data = d;
    new_node -> next = table[hashValue];
    table[hashValue] = new_node;
}

void del_dupl(DLINK head)
{
    HashNode* hashTable[TABLE_SIZE] = { NULL };
    DLINK current = head;

    while (current != NULL) {
        if (find(hashTable, current -> d)) {
            DLINK to_delete = current;
            if (current -> prev != NULL) {
                current -> prev -> next = current -> next;
            }
            if (current -> next != NULL) {
                current -> next -> prev = current -> prev;
            }

            current = current -> next;
            free(to_delete);
        }
        else {
            insert_hash(hashTable, current -> d);
            current = current -> next;
        }
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* node = hashTable[i];
        while (node != NULL) {
            HashNode* temp = node;
            node = node -> next;
            free(temp);
        }
    }
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
        {"Alice", 25, 50},  // Duplicate
        {"Eve", 25, 50},
        {"Charlie", 35, 85},
    };

    h = create_dl(d, size);
    print_list(h);
    putchar('\n');

    del_dupl(h);
    printf("After removing duplicates:\n");
    print_list(h);
    putchar('\n');

    return 0;
}