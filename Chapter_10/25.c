/* Chapter 10 exercise 25 */

/* 함수 원형이 다음과 같은 함수를 작성하여라.

    data *queue_to_data(queue q);
 
 * 이 함수는 큐의 원소의 값으로 data 배열을 만드는 것이다. 배열의 크기는
 * q.cnt 이어야 한다.
 */

#include "queue/queue.h"

data *queue_to_data(queue q)
{
    data *d = (data*) malloc(q.cnt * sizeof(data));
    
    if (d == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    queue q_copy = q;

    for (int i = 0; i < q.cnt; i++){
        d[i] = dequeue(&q_copy);
    }
    return d;
}