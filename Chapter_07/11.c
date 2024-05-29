/* Chapter 7 exercise 11 */

/* 상수 0xff, 0xff00, 0xff0000, 0xff000000을 마스크로 사용하는 데 익숙하지
 * 않다면, bit_print() 함수를 사용하여 이들의 값을 비트열로 출력하는 프로그램
 * 을 작성해 보아라.
 */

#include <stdio.h>
#include <limits.h>

void bit_print(int a)
{
    int i;
    int n = sizeof(int) * CHAR_BIT;
    int mask = 1 << (n - 1);

    for (i = 1; i <= n; ++i){
        putchar(((a & mask) == 0) ? '0' : '1');
        a <<= 1;

        if (i % CHAR_BIT == 0 && i < n)
            putchar(' ');
    }
    putchar('\n');
}

int main(void)
{
    int a = 0xff;
    int b = 0xff00;
    int c = 0xff0000;
    int d = 0xff000000;

    bit_print(a);
    bit_print(b);
    bit_print(c);
    bit_print(d);
    return 0;
}