/* Chapter 10 exercise 28 */

/* 연습 문제 27번에서 작성한 프로그램을 우선 순위를 허용하는 것으로 수정하여라.
 * data 형을 프로세서 ID 번호와 우선 순위를 갖는 구조체로 변경하여라. 우선 순위
 * 는 0과 9 사이의 unsigned 숫자이다. 높은 우선 순위 프로세스가 먼저 서비스되는
 * 스케줄을 사용하여라. 주의: "프로세스"와 "프로세서"를 혼동하지 말아야 한다.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define EMPTY   0
#define FULL    10000

typedef struct priority_data {
    unsigned int pid;
    unsigned int priority;
} priority_data;

typedef enum {false, true} boolean;

struct elem {       // an element in the queue
    priority_data d;
    struct elem *next;
};

typedef struct elem elem;

struct queue {
    int cnt;        // a count of the elemetns
    elem *front;    // ptr to the front element
    elem *rear;     // ptr to the rear element
};

typedef struct queue queue;

void initialize(queue *q);
void enqueue(priority_data d, queue *q);
priority_data dequeue(queue *q);
priority_data front(const queue *q);
boolean empty(const queue *q);
boolean full(const queue *q);

int main(void)
{
    int ch;
    int cnt_a = 0;
    int cnt_b = 0;
    int cnt_c = 0;
    int cnt_d = 0;
    
    priority_data pd;           // process id number
    queue a, b, c, d;

    initialize(&a);
    initialize(&b);
    initialize(&c);
    initialize(&d);

    // Enqueue the requests.
    while ((ch = getchar()) != EOF) {
        switch (ch) {
        case 'A':
            assert(scanf("%u %u", &pd.pid, &pd.priority) == 2);
            if (!full(&a))
                enqueue(pd, &a);
            break;
            
        case 'B':
            assert(scanf("%u %u", &pd.pid, &pd.priority) == 2);
            if (!full(&b))
                enqueue(pd, &b);
            break;

        case 'C':
            assert(scanf("%u %u", &pd.pid, &pd.priority) == 2);
            if (!full(&c))
                enqueue(pd, &c);
            break;

        case 'D':
            assert(scanf("%u %u", &pd.pid, &pd.priority) == 2);
            if (!full(&d))
                enqueue(pd, &d);
            break;
        }
    }

    // Dequeue the requests and print them.
    printf("\nA's schedule:\n");
    while (!empty(&a)) {
        pd = dequeue(&a);
        printf("JOB %u is %u with priority %u \n", ++cnt_a, pd.pid, pd.priority);
    }
    
    printf("\nB's schedule:\n");
    while (!empty(&b)) {
        pd = dequeue(&b);
        printf("JOB %u is %u with priority %u \n", ++cnt_b, pd.pid, pd.priority);
    }

    printf("\nC's schedule:\n");
    while (!empty(&c)) {
        pd = dequeue(&c);
        printf("JOB %u is %u with priority %u \n", ++cnt_c, pd.pid, pd.priority);
    }

    printf("\nD's schedule:\n");
    while (!empty(&d)) {
        pd = dequeue(&d);
        printf("JOB %u is %u with priority %u \n", ++cnt_d, pd.pid, pd.priority);
    }
    return 0;
}


void initialize(queue *q)
{
    q -> cnt = 0;
    q -> front = NULL;
    q -> rear = NULL;
}

void enqueue(priority_data d, queue *q)
{
    elem *p, *prev = NULL, *current = q -> front;

    p = (elem*)malloc(sizeof(elem));
    p -> d = d;
    p -> next = NULL;

    while (current != NULL && current -> d.priority >= d.priority) {
        prev = current;
        current = current -> next;
    }

    if (prev == NULL) {
        p -> next = q -> front;
        q -> front = p;
    } else {
        prev -> next = p;
        p -> next = current;
    }

    if (p -> next == NULL){
        q -> rear = p;
    }

    q -> cnt++;
}

priority_data dequeue(queue *q)
{
    priority_data d;
    elem *p;

    d = q -> front -> d;
    p = q -> front;
    q -> front = q -> front -> next;
    q -> cnt--;

    if (q -> front == NULL){
        q -> rear = NULL;
    }

    free(p);
    return d;
}

priority_data front(const queue *q)
{
    return (q -> front -> d);
}

boolean empty(const queue *q)
{
    return ((boolean) (q -> cnt == EMPTY));
}

boolean full(const queue *q)
{
    return ((boolean) (q -> cnt == FULL));
}
