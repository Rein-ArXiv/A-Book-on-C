/* Chapter 6 exercise 37 */

/* int 형 배열이 아닌 char 형 포인터의 배열에 대해 동작하도록 앞에서 제시한
 * merge() 함수와 연습 문제 16번에서 작성한 mergesort() 함수를 수정하여라.
 * 또한 6.13절의 sort_words 프로그램을 수정하여 char 형 포인터 배열을 정렬하
 * 도록 하여라. 이 두 버전의 프로그램을 큰 파일과 함께 수행했을 때의 수행 시간
 * 을 각각 구하여라. mergesort()를 사용하는 프로그램의 수행 시간이 더 빠를 것
 * 이다. 그러한가?
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort/sort.h"

void merge(char *arr[], int l, int m, int r);
void mergesort(char *arr[], int l, int r);

int main(void)
{
    char *words[] = {"Hello", "What", "is", "your", "name"};
    int arr_length = sizeof(words) / sizeof(words[0]);

    printf("Before sort:\n");
    for (int i = 0; i < arr_length; ++i) {
        printf("%s ", words[i]);
    }
    printf("\n");

    sort_words(words, arr_length);

    printf("After sort:\n");
    for (int i = 0; i < arr_length; ++i) {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}

void mergesort(char *arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void merge(char *arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    char *L[n1], *R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (strcmp(L[i], R[j]) <= 0)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
