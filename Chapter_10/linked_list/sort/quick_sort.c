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
    return temp;
}

struct Node* partition(struct Node* first, struct Node* last)
{
    // Get first node of given linked list
    struct Node* pivot = first;
    struct Node* front = first;

    int temp = 0;

    while (front != NULL && front != last) {
        if (front -> data < last -> data) {
            pivot = first;

            // Swapping node values
            temp = first -> data;
            first -> data = front -> data;
            front -> data = temp;

            // Visiting the next node
            first = first -> next;
        }

        // Visiting the next node
        front = front -> next;
    }

    // Change last node value to current node
    temp = first -> data;
    first -> data = last -> data;
    last -> data = temp;
    return pivot;
}

void quick_sort(struct Node* first, struct Node* last)
{
    if (first == last) {
        return;
    }

    struct Node* pivot = partition(first, last);

    if (pivot != NULL && pivot -> next != NULL) {
        quick_sort(pivot -> next, last);
    }

    if (pivot != NULL && first != pivot) {
        quick_sort(first, pivot);
    }
}

// Driver's code
int main()
{
    struct Node* head = NULL;

    // Create linked list
    insert(&head, 15);
    insert(&head, 10);
    insert(&head, 5);
    insert(&head, 20);
    insert(&head, 3);
    insert(&head, 2);
    printf("\n Before Sort ");
    display(head);

    // Function call
    quick_sort(head, last_node(head));
    printf("\n After Sort ");
    display(head);
    return 0;
}
