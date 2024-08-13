/* Chapter 8 exercise 27 */

/* 피봇 원소를 찾기 위해, 배열의 세 원소 중에서 하나를 선택하였다. 만일 5개의
 * 원소 중에서 선택한다면, 실행 시간은 어느 정도 줄어들어야 한다. quicksort 코
 * 드를 수정하여 이 기법을 구현해 보아라. 이때 적절한 곳에 매크로를 사용해야 한
 * 다. 실행 시간의 감소 여부를 검사하는 프로그램을 작성하여라. 피봇을 찾는 최적
 * 의 전략은 배열의 자료에 따라 다르다. 5개의 원소 중에서 피봇을 선택하는 것이
 * 일반적인 전략이다. 만일 7개의 원소 중에서 피봇을 선택한다면 어떻게 되겠는가?
 * 이것 또한 시험해 보아라.
 */

// Compile with quicksort/quicksort_pivot.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define    N    100000  // 원래 크기 유지

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
    quicksort(a, a + N - 1);
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
    quicksort(a, a + N - 1);
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
    quicksort(a, a + N - 1);
    end = time(NULL);
    printf("Start time: %ld\n", start);
    printf("End time: %ld\n", end);
    printf("Elapsed time: %ld seconds\n", end - start);
    printf("Calculation count: %d\n", cnt);
    print_array(a, N);

    return 0;
}
