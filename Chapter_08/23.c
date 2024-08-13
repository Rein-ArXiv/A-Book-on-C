/* Chapter 8 exercise 23 */

/* 연습 문제 22번에서 각 원소가 구간 [0, 999] 사이에서 무작위로 분포된 임의의 정
 * 수를 갖는 크기가 10,000인 배열을 정렬해 보았다. 이번에는 프로그램의 실행 시간
 * 을 측정하면서 이 프로그램을 다시 실행시켜 보아라. 그리고 배열의 원소가 구간
 * [0, 9] 사이에 무작위로 분포된 값을 갖도록 프로그램을 수정한 후 다시 수행해 보
 * 아라. 왜 시간 차이가 나는지 설명해 보아라.
 */

// Compile with quicksort/quicksort.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define    N    10000

void quicksort(int *, int *);

int main(void)
{
    int a[N], i;

    srand(time(NULL));      // seed the random number generator
    
    for (i = 0; i < N; ++i)
        a[i] = rand() % 1000;
    
    printf("Before sort ticks: %ld\n", clock());
    quicksort(a, a + N - 1);
    printf("After sort ticks: %ld\n", clock());
    putchar('\n');

    for (i = 0; i < N; i+= 200){
        printf("%d ", a[i]);
    }
    putchar('\n');
    
    for (i = 0; i < N; ++i)
        a[i] = rand() % 10;
    
    printf("Before sort ticks: %ld\n", clock());
    quicksort(a, a + N - 1);
    printf("After sort ticks: %ld\n", clock());
    putchar('\n');
    
    for (i = 0; i < N; i+= 200){
        printf("%d ", a[i]);
    }

    return 0;
}