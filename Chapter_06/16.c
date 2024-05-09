/* Chapter 6 exercise 16 */

/* mergesort() 함수를 2의 거듭제곱 크기에 대해서만이 아니라 임의의 크기의 배
 * 열에 대해서도 사용할 수 있도록 수정하여라. 이때 임의의 양수는 2의 거듭제곱의
 * 합으로 표현할 수 있음을 상기하여라. 예를 들면 다음과 같다.
 
    27 = 16 + 8 + 2 + 1
 
 * 배열을 2의 거듭제곱 크기의 부분 배열의 집합으로 생각해 보자. 각 부분 배열을
 * 정렬하고, 최종적으로 정렬된 배열을 만들기 위해 merge()를 사용하여라.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergesort(int a[], int n);
void merge(int a[], int b[], int c[], int m, int n);

int main(void)
{
    srand(time(NULL));
    
    int i, n = 10;
    int arr[n];

    for (i = 0; i < n; i++){
        arr[i] = rand();
    }

    return 0;
}

void mergesort(int key[], int n)
{
    if (n <= 1) return;

    int j, k, *w;

    w = calloc(n, sizeof(int)); // allocate workspace
    assert(w != NULL); // check that calloc() worked
    for (k = 1; k < n; k*=2){
        for (j = 0; j < n - k; j += 2 * k)
            // Merge two subarrays of key[] into a subarray of w[].
            merge(key + j, key + j + k, w + j, k, k);
        for (j = 0; j < n; ++j)
            key[j] = w[j];
    }
    free(w);
}

void merge(int a[], int b[], int c[], int m, int n)
{
    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];

    while (i < m)
        c[k++] = a[i++];

    while (j < n)
        c[k++] = b[j++];
}