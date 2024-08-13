/* Chapter 8 exercise 34 */

/* 연습 문제 33번에서, 큰 배열을 사용하여 qsort()와 quicksort()의 수행시간
 * 비율을 구하였다. 이번에는 [0, 100000] 구간에 무작위로 분포된 원소를 가지는 배
 * 열을 정렬하는데 걸리는 시간과 [0, 1] 구간에 무작위로 분포된 원소를 가지는 배
 * 열을 정렬하는데 걸리는 시간의 비율을 구하여라. 이번 연습 문제의 결과에 매우
 * 놀랄 것이다. 한 번 시도해 보아라.
 */

// Compile with quicksort/quicksort.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define    N    100000

void quicksort(int *, int *);

void fill_random(int *a, int n) {
    for (int i = 0; i < n; ++i)
        a[i] = rand() % 2;
}

void copy_array(int *to, int *from, int size){
    for (int i = 0; i < size; i++){
        to[i] = from[i];
    }
}

int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void)
{
    int *a = (int *)malloc(N * sizeof(int));
    int *b = (int *)malloc(N * sizeof(int));
    
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    if (b == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
e
    srand(time(NULL));      // seed the random number generator

    // Randomly filled array
    fill_random(a, N);
    copy_array(b, a, N);

    printf("Randomly filled array (size %d):\n", N);
    clock_t start = clock();
    quicksort(a, a + N - 1);
    clock_t end = clock();
    printf("Quicksort - Elapsed time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    qsort(b, N, sizeof(int), compare_int);
    end = clock();
    printf("Qsort - Elapsed time: %.6f seconds\n\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(a);
    free(b);

    return 0;
}
