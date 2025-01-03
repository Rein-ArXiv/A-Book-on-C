#include "mergesort.h"
#include <time.h>

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("정렬 전 배열: ");
    wrt(arr, n);

    // 정렬 시간 측정
    clock_t start = clock();
    mergesort(arr, 0, n - 1);
    clock_t end = clock();

    // 정렬 후 결과 출력
    printf("정렬 후 배열: ");
    wrt(arr, n);

    // 정렬 시간 계산 및 출력 (밀리초 단위)
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("정렬 시간: %f 밀리초\n", time_taken);

    return 0;
}