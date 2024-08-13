/* Chapter 9 exercise 28 */

/* (프로젝트) 양쪽으로 끝이 있는 큐는 매우 유용한 ADT이다. 다음과 같이 시작하
 * 는 큐 ADT를 구현하여라.

    struct deque {              // double ended queue
        .....
    };

    typedef struct deque        deque;
    typedef enum {false, true}  boolean;
    typedef char                data;

 * 프로그래머 정의형 deque는 배열을 사용하여 구현된다. 만일 정수형의 자료를 큐
 * 에 저장하고자 한다면, 마지막 typedef를 다음으로 대치하여라.

    typedef int data;

 * 다음 함수 원형들은 큐에 필요한 연산자들이다.

    void add_to_front(deque *, data);
    void add_to_rear(deque *, data);
    data take_from_front(deque *);
    data take_from_front(deque *);
    boolean empty(deque *);
    boolean full(deque *);

 * 이 큐 ADT를 구현하고 검사하여라. (10.7절에서는 큐를 연결 리스트로 구현할 것
 * 이다.)
 */

#include <stdio.h>

#define MAX_LEN 1000

struct deque {              // double ended queue
    char s[MAX_LEN];
    int front;
    int rear;
    int count;
};

typedef struct deque        deque;
typedef enum {false, true}  boolean;
typedef char                data;
// typedef int              data;

void reset(deque *q);
void add_to_front(deque *q, data d);
void add_to_rear(deque *q, data d);
data take_from_front(deque *q);
data take_from_rear(deque *q);
boolean empty(deque *q);
boolean full(deque *q);

int main(void)
{
    char str[] = "My name is Laura Pohl!";
    int i;
    deque q;

    reset(&q);
    printf("In the string: %s\n", str);

    for (i = 0; str[i] != '\0'; ++i){
        add_to_rear(&q, str[i]);
    }
    
    printf("From the deque front: ");

    while (!empty(&q))
        printf("%c", take_from_front(&q));
    printf("\n");

    for (i = 0; str[i] != '\0'; ++i)
        add_to_front(&q, str[i]);
    
    printf("From the deque rear: ");
    while (!empty(&q))
        printf("%c", take_from_rear(&q));
    printf("\n");

    return 0;
}

void reset(deque *q)
{
    q -> front = 0;
    q -> rear = -1;
    q -> count = 0;
}

void add_to_front(deque *q, data d)
{
    if (full(q)){
        printf("Deque is Full. Cannot add to front.\n");
        return;
    }

    q -> front = (q -> front + MAX_LEN - 1) % MAX_LEN;
    q -> s[q -> front] = d;
    q -> count++;
}

void add_to_rear(deque *q, data d)
{
    if (full(q)){
        printf("Deque is Full. Cannot add to rear.\n");
        return;
    }

    q -> rear = (q -> rear + 1) % MAX_LEN;
    q -> s[q -> rear] = d;
    q -> count++;
}

data take_from_front(deque *q)
{
    if (empty(q)){
        printf("Deque is Empty. Cannot take from front.\n");
        return 0;
    }

    data d = q -> s[q -> front];
    q -> front = (q -> front + 1) % MAX_LEN;
    q -> count--;
    return d;
}

data take_from_rear(deque *q)
{
    if (empty(q)){
        printf("Deque is Empty. Cannot take from front.\n");
        return 0;
    }

    data d = q -> s[q -> rear];
    q -> rear = (q -> rear + MAX_LEN - 1) % MAX_LEN;
    q -> count--;
    return d;
}

boolean full(deque *q)
{
    return (boolean) (q -> count == MAX_LEN);
}

boolean empty(deque *q)
{
    return (boolean) (q -> count == 0);
}