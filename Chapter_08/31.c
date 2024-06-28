/* Chapter 8 exercise 31 */

/* 8.15절에서 partition() 함수의 코드를 설명한 다음 외부 while 루프의 각 단계
 * 마다 a[]의 상태를 보여주는 표를 제시하였다. 최대한의 단계를 생성하는 12개의
 * 서로 다른 원소로 구성된 배열을 구하여라. 그리고 각 단계 때마다 배열 내용을
 * 보여주는 표를 작성하여라. 교체된 원소들은 사각형으로 표시하여라. 먼저 손으로
 * 해본 후에, 이 표를 생성하는 프로그램을 작성하여라. 각 단계에서 교체된 원소를
 * 나타내기 위해 그 원소들을 큰따움표로 묶어도 좋다.
 */

// Compile with quicksort/quicksort_show.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 12

extern int cnt;

void quicksort(int *, int *);

int main(void)
{
    int a[N] = {11, 12, 1, 10, 2, 9, 3, 8, 4, 7, 5, 6};

    quicksort(a, a + N - 1);
    printf("Count: %d\n", cnt);
    return 0;
}
