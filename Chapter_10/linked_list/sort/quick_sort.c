#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Add new node at end of linked list
void insert(struct Node** head, int value)
{
    // Create dynamic node
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));

    if (node == NULL){
        // checking memory overflow
        printf("Memory overlfow\n");
    }
    else {
        node -> data = value;
        node -> next = NULL;

        if (*head == NULL) {
            *head = node;
        }
        else {
            struct Node* temp = *head;

            while (temp -> next != NULL) {
                temp = temp -> next;
            }

            temp -> next = node;
        }
    }
}

void display(struct Node* head)
{
    if (head == NULL) {
        printf("Empty linked list\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked list:\n");
    while (temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

struct Node* last_node(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL && temp -> next != NULL) {
        temp = temp -> next;
    }
}