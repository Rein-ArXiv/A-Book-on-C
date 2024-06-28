/* Chapter 8 exercise 25 */

/* 만일 배열이 적은 원소를 갖고 있다면, 예를 들어 7개 이하, 버블 정렬이나 치환
 * 정렬이 퀵 정렬보다 빨라야 한다. 다음 quicksort() 버전은 이러한 사실을 고려
 * 한 것이다.
 
    int quicksort(int *left, int *right)
    {
        int *p, *w, pivot;
        static int cnt = 0;

        if (right - left < 7) {
            for (p = left; p < right; ++p)
                for (q = p + 1; q <= right; ++q)
                    if(*p > *q)
                        swap(*p, *q);
        }

        else if (find_pivot(left, right, &pivot) == yes) {
            p = partition(left, right, pivot);
            quicksort(left, p-1);
            quicksort(p, right);
        }
        return ++cnt;
    }

 * 변수 cnt의 사용을 주목하여라. 함수를 호출한 곳으로 리턴되는 값은 함수가 호
 * 출된 횟수이다. 이 새로운 quicksort()가 과연 빠르게 실행되는지를 실험해 보
 * 아라. 실행 시간과 함수가 호출된 횟수 사이에는 상관관계가 있는가?
 */

// Compile with quicksort/quicksort_count.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define    N    7

extern int cnt;  // 외부에서 정의된 cnt 변수를 사용

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
    printf("Calculation count: %d\n", cnt);
    putchar('\n');
 
    for (i = 0; i < N; i++){
        printf("%d ", a[i]);
    }
    putchar('\n');
    return 0;
}
