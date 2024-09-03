/* Chapter 10 exercise 24 */

/* 함수 원형이 다음과 같은 함수를 작성하여라.

    queue *data_to_queue(data d[], int n);
 
 * 여기서 n은 배열 d의 크기이다. data 형의 배열이 전달되면, 이 함수는 배열의
 * 원소를 사용하여 큐를 만들어서 리턴해야 한다.
 */

#include "queue/queue.h"

queue *data_to_queue(data d[], int n)
{
    queue *q = (queue*)malloc(sizeof(queue));

    if (q == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    initialize(q);

    for (int i = 0; i < n; i++){
        enqueue(d[i], q);
    }
    return q;
}