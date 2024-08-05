#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* sorted = NULL;

void push(int val)
{
    // allocate node
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode -> data = val;
    newnode -> next = head;
    head = newnode;
}

void sortedInsert(struct node* newnode)
{
    // special case for the head end
    if (sorted == NULL || sorted -> data >= newnode -> data)
    {
        newnode -> next = sorted;
        sorted = newnode;
    }
    else {
        struct node* current = sorted;
        // Locate the node before the point of insertion

        while (current -> next != NULL && current -> next -> data < newnode -> data) {
            current = current -> next;
        }
        newnode -> next = current -> next;
        current -> next = newnode;
    }
}

// Function to sort a singly linked list
void insertionsort()
{
    struct node* current = head;

    // Traverse the given linked list and insert every node to sorted
    while (current != NULL) {
        // Store next for next iteration
        struct node* next = current -> next;
        sortedInsert(current);
        current = next;
    }
    head = sorted;
}

void printlist(struct node* head)
{
    while (head != NULL) {
        printf("%d -> ", head -> data);
        head = head -> next;
    }
    printf("NULL\n");
}

int main(void)
{
    push(5);
    push(20);
    push(4);
    push(3);
    push(30);

    printf("Linked list before sorting:\n");
    printlist(head);
    printf("\n");

    insertionsort(head);

    printf("Linked list after sorting:\n");
    printlist(head);

    return 0;
}