/* Chapter 8 exercise 32 */

/* quicksort()와 mergesort()를 비교해 보아라. (6장을 참조하여라.) 100, 1,000,
 * 10,000개의 원소를 갖는 배열로 두 함수의 수행 시간을 조사해 보아라. 적은 양의
 * 자료에 대해서는 실행 시간 오버헤드가 수행 시간을 좌우한다. 즉 함수 설정, 변
 * 수 초기화 및 기타 단계들이 실제 정렬을 수행하는 작업을 좌우하게 된다. 큰 크
 * 기의 배열에 대해서 quicksort()는 mergesort()보다 빨라야 한다. 과연 그러한
 * 가?
 */

// Compile with
// quicksort/quicksort_count.c
// ../Chapter_06/mergesort/mergesort.h
// ../Chapter_06/mergesort/merge.c
// ../Chapter_06/mergesort/mergesort.c
// ../Chapter_06/mergesort/wrt.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Chapter_06/mergesort/mergesort.h"

#define    N1    100
#define    N2    1000
#define    N3    10000

extern int cnt; // For counting quicksort operations

void quicksort(int *, int *);

void fill_random(int *a, int n) {
    for (int i = 0; i < n; ++i)
        a[i] = rand() % 1000;
}

void fill_sorted(int *a, int n) {
    for (int i = 0; i < n; ++i)
        a[i] = i;
}

void fill_reverse_sorted(int *a, int n) {
    for (int i = 0; i < n; ++i)
        a[i] = n - i;
}

void test_sort(int size) {
    int *a = (int *)malloc(size * sizeof(int));
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    srand(time(NULL));      // seed the random number generator

    // Randomly filled array
    fill_random(a, size);
    cnt = 0; // reset count
    printf("Randomly filled array (size %d):\n", size);
    clock_t start = clock();
    quicksort(a, a + size - 1);
    clock_t end = clock();
    printf("Quicksort - Elapsed time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Calculation count: %d\n", cnt);

    fill_random(a, size);
    start = clock();
    mergesort(a, 0, size - 1);
    end = clock();
    printf("Mergesort - Elapsed time: %.6f seconds\n\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Already sorted array
    fill_sorted(a, size);
    cnt = 0; // reset count
    printf("Already sorted array (size %d):\n", size);
    start = clock();
    quicksort(a, a + size - 1);
    end = clock();
    printf("Quicksort - Elapsed time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Calculation count: %d\n", cnt);

    fill_sorted(a, size);
    start = clock();
    mergesort(a, 0, size - 1);
    end = clock();
    printf("Mergesort - Elapsed time: %.6f seconds\n\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Reverse sorted array
    fill_reverse_sorted(a, size);
    cnt = 0; // reset count
    printf("Reverse sorted array (size %d):\n", size);
    start = clock();
    quicksort(a, a + size - 1);
    end = clock();
    printf("Quicksort - Elapsed time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Calculation count: %d\n", cnt);

    fill_reverse_sorted(a, size);
    start = clock();
    mergesort(a, 0, size - 1);
    end = clock();
    printf("Mergesort - Elapsed time: %.6f seconds\n\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(a);
}

int main(void)
{
    test_sort(N1);
    test_sort(N2);
    test_sort(N3);

    return 0;
}
