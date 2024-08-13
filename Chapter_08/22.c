/* Chapter 8 exercise 22 */

/* 8.15절의 quicksort 코드를 검사하는 프로그램을 작성하여라. 프로그램은 다음과
 * 같은 코드로 시작해야 한다.

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    #define    N    10000
    void quicksort(int *, int *);
    
    int main(void)
    {
        int a[N], i;

        srand(time(NULL));      // seed the random number generator
        for (i = 0; i < N; ++i)
            a[i] = rand() % 1000;
        quicksort(a, a + N - 1);
        .....

 * 정렬된 배열의 원소를 출력할 수 있도록 프로그램을 완성하여라. 만일 모든 원소
 * 를 보기가 지루하다면, 그 배열이 정렬되었음을 알 수 있게 그 배열의 첫 번째
 * 값, 중간 값, 마지막 값만을 출력해도 좋다.
 */

// Compile with quicksort/quicksort.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define    N    10000

void quicksort(int *, int *);

int main(void)
{
    int a[N], i;

    srand(time(NULL));      // seed the random number generator
    for (i = 0; i < N; ++i)
        a[i] = rand() % 1000;
    quicksort(a, a + N - 1);


    for (i = 0; i < N; i+= 200){
        printf("%d ", a[i]);
    }
    putchar('\n');
    return 0;
}