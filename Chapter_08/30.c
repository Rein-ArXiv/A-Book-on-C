/* Chapter 8 exercise 30 */

/* 크기가 n인 배열의 최적 분할 크기는 n/2이다. 이것은 계속 처리될 두 부분 배열
 * 의 크기가 서로 같거나 똔느 거의 비슷함을 의미한다. 예를 들어, 크기가 100인
 * 배열이 주어졌을 때, 최적의 분할 크기는 50이다. 분할 크기가 49라면, 이것은 부
 * 분 배열의 크기가 각각 49와 51임을 나타낸다. 그리고, 분할 크기가 51이라면, 이
 * 것은 부분 배열의 크기가 각각 51과 49임을 나타낸다. 따라서 분할 크기 49와 51
 * 은 같다. 연습 문제 27번에서 작성한 프로그램을 수정하여, partition()에서 구
 * 한 분할 크기가 k일 때, k - 50의 절대값의 평균값을 추적하도록 하여라. 이 평균
 * 값은 분핳 크기가 얼마나 양호한지에 반비례한다. 좀더 일반적으로, 다음과 같이
 * 정의하여라.
 
    $m = = {\abs{k - (n/2)} \over n}$

 * 여기서 k는 크기가 n인 배열에 대해 partition()을 수행했을 때 구한 분할 크
 * 기이다. 배열 원소를 무작위로 채우고, m이 어떤 값을 갖는지 보기 위해 프로그
 * 램을 수행해 보아라.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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
    int pivot, repeat = 100;
    double segment_size, total_segment_size = 0;
    srand(time(NULL));      // seed the random number generator

    while (repeat){
        fill_random(a, N);
        printf("Count %d:\n", 100 - repeat + 1);
        
        if (find_pivot(a, a + N - 1, &pivot) == yes) {
            int *p = partition(a, a + N - 1, pivot);
            segment_size = p - a;
        } else {
            segment_size = N;
        }
        segment_size = fabs(segment_size - (N / 2));

        printf("Pivot: %d\n", pivot);
        printf("Partition size: %lf\n", segment_size);

        total_segment_size += segment_size;
        repeat--;
    }

    printf("Average partition size: %lf\n", (double) total_segment_size / N);

    return 0;
}