/* Chapter 8 exercise 26 */

/* 퀵 정렬에서 피봇 원소를 잘 찾아내는 알고리즘은 매우 중요하다. 간단한 알고리
 * 즘은 배열에서 두 개의 다른 원소를 찾아내어 그중 큰 것을 피봇으로 선택하는
 * 것이다. 이 알고리즘을 사용하면, 퀵 정렬은 배열이 이미 정렬되어 있거나 또는
 * 거의 정렬된 형태일 때 n log n보다는 n^2에 비례하는 시간이 거린다. 이것은 매우
 * 중요한 사실이다. 왜냐하면 실질적으로 배열은 초기에 부분적으로 정렬되어 있는
 * 상태일 경우가 종종 있기 때문이다. 이 알고리즘을 사용하도록 quicksort 코드
 * 를 다시 작성하고, 배열이 초기에 정렬된 상태일 때 퀵 정렬이 매우 비효율적임을
 * 증명하는 검사 프로그램을 작성해 보아라. 만일 배열이 역순으로 정렬되어 있다
 * 면, 어떻게 되겠는가?
 */

// Compile with quicksort/quicksort_simple.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define    N    10000

extern int cnt;

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
    
    return 0;
}