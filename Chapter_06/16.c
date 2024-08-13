/* Chapter 6 exercise 16 */

/* mergesort() 함수를 2의 거듭제곱 크기에 대해서만이 아니라 임의의 크기의 배
 * 열에 대해서도 사용할 수 있도록 수정하여라. 이때 임의의 양수는 2의 거듭제곱의
 * 합으로 표현할 수 있음을 상기하여라. 예를 들면 다음과 같다.
 
    27 = 16 + 8 + 2 + 1
 
 * 배열을 2의 거듭제곱 크기의 부분 배열의 집합으로 생각해 보자. 각 부분 배열을
 * 정렬하고, 최종적으로 정렬된 배열을 만들기 위해 merge()를 사용하여라.
 */

#include "mergesort/mergesort.h"

int main()
{
    int arr[] = {12, 11, 13, 7, 3, 5};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array:  ");
    wrt(arr, arr_size);

    mergesort(arr, 0, arr_size - 1);

    printf("Sorted array: ");
    wrt(arr, arr_size);
    return 0;
}