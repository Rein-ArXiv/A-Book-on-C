/* Chapter 7 exercise 3 */

/* 다음과 같이 시작되는 함수를 작성하여라.
 
    int circular_shift(int a, int n)
    {
        .....

 * 이 함수는 a를 n만큼 왼쪽으로 이동하는 함수로, 이동할 때 상위 비트가 다시 하
 * 위 비트로 들어오도록 해야 한다. 다음은 char 형에 대해 정의된 순환 이동 연산
 * 의 두 가지 예이다.
 
    10000001을 1 만큼 순환 이동하면 0000011이 된다.
    01101011을 3 만큼 순환 이동하면 01011011이 된다.

 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

short majority(short a, short b, short c)
{
    short result = 0;
    short n = sizeof(short) * CHAR_BIT;
    short mask = 1;
    int count = 0;
    
    for (int i = 1; i <= n; i++){
        count = 0;
        if (a & mask)
            count++;
        
        if (b & mask)
            count++;
        
        if (c & mask)
            count++;
        
        if (count >= 2){
            result += 1 * mask;
        }
    }
    return result;
}

void short_bit_print(short a)
{
    short i;
    short n = sizeof(short) * CHAR_BIT;
    short mask = 1 << (n - 1);

    
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
    srand(time(NULL));
    short a, b, c, result;
    
    a = rand() % SHRT_MAX;
    b = rand() % SHRT_MAX;
    c = rand() % SHRT_MAX;
    
    printf("Alice: ");
    short_bit_print(a);
    printf("Betty: ");
    short_bit_print(b);
    printf("Carole: ");
    short_bit_print(c);
    
    result = majority(a, b, c);
    
    printf("Result: ");
    short_bit_print(result);

    return 0;
}

