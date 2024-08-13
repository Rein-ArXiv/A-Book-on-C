/* Chapter 8 exercise 28 */

/* a[]는 크기가 100인 정수 배열이고, 각 i에 대해 원소 a[i]는 i 값을 가진다고
 * 가정하자. 만일 quicksort(a, a + 99)로 호출하면, quicksort() 함수는 얼마나
 * 많이 호출되겠는가? find_pivot()의 각 버전에 대해 이 횟수를 계산해 보아라.
 */

// Compile with quicksort/quicksort_pivot.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define    N    100  // 원래 크기 유지

extern int cnt;

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

void print_array(const int *a, int n) {
    for (int i = 0; i < n; i+=1000) {
        printf("%d ", a[i]);
    }
    putchar('\n');
}

int main(void)
{
    int a[N];
    srand(time(NULL));      // seed the random number generator

    // Randomly filled array
    fill_random(a, N);
    cnt = 0; // reset count
    print_array(a, N);
    printf("Randomly filled array:\n");
    time_t start = time(NULL);
    quicksort(a, a + 99);
    time_t end = time(NULL);
    printf("Start time: %ld\n", start);
    printf("End time: %ld\n", end);
    printf("Elapsed time: %ld seconds\n", end - start);
    printf("Calculation count: %d\n", cnt);
    print_array(a, N);

    // Already sorted array
    fill_sorted(a, N);
    cnt = 0; // reset count
    printf("Already sorted array:\n");
    start = time(NULL);
    quicksort(a, a + 99);
    end = time(NULL);
    printf("Start time: %ld\n", start);
    printf("End time: %ld\n", end);
    printf("Elapsed time: %ld seconds\n", end - start);
    printf("Calculation count: %d\n", cnt);
    print_array(a, N);

    // Reverse sorted array
    fill_reverse_sorted(a, N);
    cnt = 0; // reset count
    printf("Reverse sorted array:\n");
    start = time(NULL);
    quicksort(a, a + 99);
    end = time(NULL);
    printf("Start time: %ld\n", start);
    printf("End time: %ld\n", end);
    printf("Elapsed time: %ld seconds\n", end - start);
    printf("Calculation count: %d\n", cnt);
    print_array(a, N);

    return 0;
}
