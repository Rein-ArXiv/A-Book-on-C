/* Chapter 10 exercise 28 */

/* 연습 문제 27번에서 작성한 프로그램을 우선 순위를 허용하는 것으로 수정하여라.
 * data 형을 프로세서 ID 번호와 우선 순위를 갖는 구조체로 변경하여라. 우선 순위
 * 는 0과 9 사이의 unsigned 숫자이다. 높은 우선 순위 프로세스가 먼저 서비스되는
 * 스케줄을 사용하여라. 주의: "프로세스"와 "프로세서"를 혼동하지 말아야 한다.
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
