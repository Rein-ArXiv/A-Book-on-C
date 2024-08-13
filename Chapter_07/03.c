/* Chapter 7 exercise 3 */

/* 다음과 같이 시작되는 함수를 작성하여라.
 
    int circular_shift(int a, int n)
    {
        .....

 * 이 함수는 a를 n만큼 왼쪽으로 이동하는 함수로, 이동할 때 상위 비트가 다시 하
 * 위 비트로 들어오도록 해야 한다. 다음은 char 형에 대해 정의된 순환 이동 연산
 * 의 두 가지 예이다.
 
    10000001을 1 만큼 순환 이동하면 00000011이 된다.
    01101011을 3 만큼 순환 이동하면 01011011이 된다.

 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INT_BIT 32

int circular_shift(int a, int n)
{
    n %= INT_BIT;

    return ((a << n) | (a >> (INT_BIT - n)));
}

void bit_print(int a)
{
    int i;
    int n = INT_BIT;
    int mask = 1 << (n - 1);

    
    for (i = 1; i <= n; i++){
        putchar(((a & mask) == 0) ? '0' : '1');

        a <<= 1;

        if (i % CHAR_BIT == 0 && i < n)
            putchar(' ');
    }
    putchar('\n');
}

int main(void)
{
    int a = 129; // 10000001
    int n = 31;
    int result = circular_shift(a, n);
    
    printf("Int a:      %d\n", a);
    printf("Bit a:      ");
    bit_print(a);

    printf("Int result: %d\n", result); // Output: 3 (00000011)
    printf("Bit result: ");
    bit_print(result);
    return 0;
}
