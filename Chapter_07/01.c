/* Chapter 7 exercise 1 */

/* 정수가 16 비트의 2의 보수 표현을 사용한다고 가정하자. -1, -5, -101, -1023의
 * 이진 표현을 기술하여라. 음수에 대한 2의 보수 표현은 그 음수에 대응되는 양수
 * 의 비트 표현을 구하고, 보수를 취한 후, 1을 더하여 구할 수 있다.
 */

#include <stdio.h>
#include <limits.h>

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
    short a, b, c, d;
   
    a = -1;
    b = -5;
    c = -101;
    d = -1023;
    
    short_bit_print(a);
    short_bit_print(b);
    short_bit_print(c);
    short_bit_print(d);
    return 0;
}

