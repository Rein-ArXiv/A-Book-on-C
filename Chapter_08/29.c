/* Chapter 8 exercise 29 */

/* parititon()에 의해 리턴되는 포인터는 원래의 배열을 두 부분으로 나누는 데
 * 사용된다. 첫 번째 부분 배열의 크기를 "분할 크기"라고 한다. 난수 발생기를 사용
 * 하여 크기가 100인 배열을 채워라. 이 배열에 대한 분할 크기를 구하기 위해
 * find_pivot()과 partition()을 호출하여라. 이러한 호출을 100번 정도 반복하
 * 여 평균 분할 크기를 추적해 보아라. 기대되는 평균 분할 크기는 배열 크기의 반
 * 이다. 실험해 본 결과 그렇게 되는가?
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort/quicksort.c"

#define    N    100 

void quicksort(int *, int *);

void fill_random(int *a, int n) {
    for (int i = 0; i < n; ++i)
        a[i] = rand() % 1000;
}

int main(void)
{
    int a[N];
    int pivot, segment_size, repeat = 100;
    srand(time(NULL));      // seed the random number generator
    int total_segment_size = 0;

    while (repeat){
        fill_random(a, N);
        printf("Count %d:\n", 100 - repeat + 1);
        
        if (find_pivot(a, a + N - 1, &pivot) == yes) {
            int *p = partition(a, a + N - 1, pivot);
            segment_size = p - a;
        } else {
            segment_size = N;
        }

        printf("Pivot: %d\n", pivot);
        printf("Segment size: %d\n", segment_size);

        total_segment_size += segment_size;
        repeat--;
    }

    printf("Average segment size: %f\n", (double) total_segment_size / 100);

    return 0;
}