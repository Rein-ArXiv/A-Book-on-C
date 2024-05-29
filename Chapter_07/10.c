/* Chapter 7 exercise 10 */

/* 2 바이트 워드나 4 바이트 워드 컴퓨터에서 모두 동작할 수 있도록 bit_print()
 * 함수를 수정하여라. 힌투: int 형의 바이트 수를 알아내기 위해 sizeof 연산자를
 * 사용하여라.
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
}
