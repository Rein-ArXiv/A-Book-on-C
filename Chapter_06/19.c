/* Chpater 6 exercise 19 */

/* 6.7절에서 제시한 bubble() 함수와 연습문제 16번에서 작성한 mergesort() 함
 * 수의 상대적 효율성을 검사하는 프로그램을 작성하여라. 배열을 초기화하기 위해
 * rand() 함수를 사용하여라. 10, 100, 500, 1000개 원소를 갖는 여러 크기의 배열에
 * 대해 프로그램을 실행해 보아라. 다양한 크기의 배열에 대해 각 정렬 방법을
 * 사용하여 수행했을 때의 수행 시간을 적어보아라. 큰 크기의 배열들에 대해서, 수
 * 행 시간의 증가는 이 교재에서 설명된 공식을 따름을 알 수 있다. 그러나 작은 크
 * 기의 배열들에 대해서는, 많은 오버헤드 때문에 이러한 증가 패턴을 검출할 수 없
 * 음을 알 수 있다. 프로그램의 실행 시간을 측정하는 방법을 모른다면 11.16절을
 * 참조하여라. UNIX 시스템을 사용한다면, 다음 명령을 사용하면 된다.
 
    time pgm

 */

#include "bubblesort/bubblesort.h"
#include "mergesort/mergesort.h"
#include <time.h>

void sort_time(int arr[], int size);
void bubblesort_time(int arr[], int size);
void mergesort_time(int arr[], int size);

int main(void)
{
    int n[] = {10, 100, 500, 1000, 100000};
    int arr1[n[0]], arr2[n[1]], arr3[n[2]], arr4[n[3]], arr5[n[4]];
    
    srand(time(NULL));
    sort_time(arr1, n[0]);
    sort_time(arr2, n[1]);
    sort_time(arr3, n[2]);
    sort_time(arr4, n[3]);
    sort_time(arr5, n[4]);

    return 0;
}

void sort_time(int arr[], int size)
{
    int i;

    for (i=0; i<size; i++)
    {
        arr[i] = rand();
    }
    bubblesort_time(arr, size);
    
    for (i=0; i<size; i++)
    {
        arr[i] = rand();
    }
    mergesort_time(arr, size);
}

void bubblesort_time(int arr[], int size)
{
    time_t bubble_start = time(NULL);
    bubble(arr, size);
    time_t bubble_end = time(NULL);
    printf("Bubble sort execution time: %lf\n", (double) bubble_end - bubble_start);
}


void mergesort_time(int arr[], int size)
{
    time_t merge_start = time(NULL);
    mergesort(arr, 0, size-1);
    time_t merge_end = time(NULL);
    printf("Merge sort execution time: %lf\n", (double) merge_end - merge_start);
}