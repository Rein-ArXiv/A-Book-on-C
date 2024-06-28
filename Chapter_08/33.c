/* Chapter 8 exercise 33 */

/* 만일 정렬할 자료의 양이 적다면, 버블 정렬이나 치환 정렬이 좋다. 자료의 양이
 * 좀더 많다면, qsort()를 사용할 수 있다. 비록 qsort()는 버블 정렬보다 훨씬
 * 빠르지만, quicksort() 만큼 빠르지는 않다. quicksort()보다 qsort()가 좋은
 * 점은 qsort()를 사용하면 단 몇 줄로 구현할 수 있다는 점이다. 반면, qsort()
 * 보다 quicksort()가 좋은 점은 빠르다는 것이다. 얼마만큼 더 빠른가? 그 답은
 * 훨씬 빠르다이다. 이것을 검사하는 프로그램을 작성하여라. 그 프로그램에서 두
 * 개의 큰 배열을 선언하여라. 무작위로 분포된 정수로 첫 번째 배열을 채우고, 그
 * 내용을 두 번째 배열에 복사하여라. 첫 번째 배열은 qsort()를 사용하여 정렬하
 * 고 그때의 수행시간을 구하여라. 그리고 두 번째 배열은 quicksort()를 사용하
 * 여 정렬하고 그때의 수행시간을 구하여라. 이 두 측정값과 그 비율을 출력하여라.
 * 시스템 오버헤드로 인해, 그 비율의 크기는 정렬되는 배열의 크기에 좌우될 것이
 * 다. 또한 퀵 정렬 알고리즘을 얼마나 잘 구현하였는가에도 좌우된다. 어느 경우이
 * 든지 간에 그 비율을 잘 기억하고 있어야 한다.
 */

// Compile with quicksort/quicksort.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define    N    100000

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

    // Already sorted array
    fill_sorted(a, N);
    copy_array(b, a, N);
    printf("Already sorted array (size %d):\n", N);
    start = clock();
    quicksort(a, a + N - 1);
    end = clock();
    printf("Quicksort - Elapsed time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    fill_sorted(a, N);
    start = clock();
    qsort(a, N, sizeof(int), compare_int);
    end = clock();
    printf("Qsort - Elapsed time: %.6f seconds\n\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Reverse sorted array
    fill_reverse_sorted(a, N);
    copy_array(b, a, N);
    printf("Reverse sorted array (size %d):\n", N);
    start = clock();
    quicksort(a, a + N - 1);
    end = clock();
    printf("Quicksort - Elapsed time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    fill_reverse_sorted(a, N);
    start = clock();
    qsort(a, N, sizeof(int), compare_int);
    end = clock();
    printf("Qsort - Elapsed time: %.6f seconds\n\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(a);
    free(b);

    return 0;
}
