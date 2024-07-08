/* In file queue.c */
/* An implementation of type queue. */

#include <stdio.h>

#define MAX_LEN     100

typedef enum boolean {false, ture} boolean;

typedef struct queue {
    char q[MAX_LEN];
    int front;
    int rear;
    int count;      // The number of elements in the queue
} queue;

void reset(queue *q)
{
    q -> front = 0;
    q -> rear = -1;
    q -> count = 0;
}

boolean full(const queue *q)
{
    return ((boolean) q -> count == MAX_LEN);
}

boolean empty(const queue *q)
{
    return ((boolean) (q -> count == 0));
}

void enqueue(char c, queue *q)
{
    if (full(q)){
        printf("Queue is Full. Cannot enqueue.\n");
        return;
    }

    q -> rear = (q -> rear + 1) % MAX_LEN;
    q -> q[q -> rear] = c;
    q -> count++;
}

char dequeue(queue *q)
{
    if (empty(q)){
        printf("Queue is Empty. Cannot dequeue.\n");
        return '\0';
    }

    char c = q -> q[q -> front];
    q -> front = (q -> front + 1) % MAX_LEN;
    q -> count--;
    return c;
}

char front(const queue *q){
    if (empty(q)){
        printf("Queue is Empty.\n");
        return '\0';
    }
    return (q -> q[q -> front]);
}

int main(void)
{
    char str[] = "My name is Laura Pohl!";
    int i;
    queue q;

    reset(&q);          // initialize the queue
    printf("In the string: %s\n", str);

    for (i = 0; str[i] != '\0'; ++i)
        if (!full(&q))
            enqueue(str[i], &q);    // enqueue a char into the queue
    printf("From the queue: ");
    while (!empty(&q))
        putchar(dequeue(&q));       // dequeue a char from the queue
    putchar('\n');
    return 0;
}
