/* In file main.c */
/* Using queues to schedule two resources. */

#include "queue.h"

int main(void)
{
    int c;
    int cnt_a = 0;
    int cnt_b = 0;
    data pid;           // process id number
    queue a, b;

    initialize(&a);
    initialize(&b);

    // Enqueue the requests.
    while ((c = getchar()) != EOF) {
        switch (c) {
        case 'A':
            assert(scanf("%u", &pid) == 1);
            if (!full(&a))
                enqueue(pid, &a);
            break;
            
        case 'B':
            assert(scanf("%u", &pid) == 1);
            if (!full(&a))
                enqueue(pid, &b);
        }
    }

    // Dequeue the requests and print them.
    printf("\nA's schedule:\n");
    while (!empty(&a)) {
        pid = dequeue(&a);
        printf("JOB %u is %d\n", ++cnt_a, pid);
    }
    printf("\nB's schedule:\n");
    while (!empty(&b)) {
        pid = dequeue(&b);
        printf("JOB %u is %d\n", ++cnt_b, pid);
    }
    return 0;
}
