/* Chapter 8 exercise 24 */

/* 퀵 정렬 알고리즘은 정수 배열뿐만 아니라 모든 종류의 배열을 정렬하는 데 사용
 * 될 수 있다. quicksort 코드를 수정하여 문자열 배열을 정렬하도록 하여라. 수정
 * 한 코드를 검사하는 프로그램을 작성하여라.
 */

// Compile with quicksort/quicksort_string.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    char *a[] = {"banana", "apple", "orange", "mango", "lemon", "peach"};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sort:\n");
    for (int i = 0; i < n; ++i) {
        printf("%s ", a[i]);
    }
    putchar('\n');

    quicksort(a, a + n - 1);

    printf("After sort:\n");
    for (int i = 0; i < n; ++i) {
        printf("%s ", a[i]);
    }
    putchar('\n');

    return 0;
}