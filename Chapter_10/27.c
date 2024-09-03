/* Chapter 10 exercise 27 */

/* 4개의 자원을 위한 스케줄러 프로그램을 작성하여라.
 */

#include "queue/queue.h"

int main(void)
{
    int ch;
    int cnt_a = 0;
    int cnt_b = 0;
    int cnt_c = 0;
    int cnt_d = 0;
    
    data pid;           // process id number
    queue a, b, c, d;

    initialize(&a);
    initialize(&b);
    initialize(&c);
    initialize(&d);

    // Enqueue the requests.
    while ((ch = getchar()) != EOF) {
        switch (ch) {
        case 'A':
            assert(scanf("%u", &pid) == 1);
            if (!full(&a))
                enqueue(pid, &a);
            break;
            
        case 'B':
            assert(scanf("%u", &pid) == 1);
            if (!full(&b))
                enqueue(pid, &b);
            break;

        case 'C':
            assert(scanf("%u", &pid) == 1);
            if (!full(&c))
                enqueue(pid, &c);
            break;

        case 'D':
            assert(scanf("%u", &pid) == 1);
            if (!full(&d))
                enqueue(pid, &d);
            break;
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

    printf("\nC's schedule:\n");
    while (!empty(&c)) {
        pid = dequeue(&c);
        printf("JOB %u is %d\n", ++cnt_c, pid);
    }

    printf("\nD's schedule:\n");
    while (!empty(&d)) {
        pid = dequeue(&d);
        printf("JOB %u is %d\n", ++cnt_d, pid);
    }
    return 0;
}
