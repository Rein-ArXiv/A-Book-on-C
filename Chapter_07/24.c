/* Chapter 7 exercise 24 */

/* 7.4절 "패킹과 언패킹"에서 제시한 pack() 함수를 생각해 보자. 이 함수의 몸체는
 * 4개의 문장으로 이루어져 있다. 이 4개의 문장이 하나의 return 문으로 통합되도
 * 록 함수를 다시 작성하여라.
 */

#include <stdio.h>
#include <limits.h>

int pack(char a, char b, char c, char d)
{
    return ((unsigned int) a << CHAR_BIT * 3) |
            ((unsigned int) b << CHAR_BIT * 2) |
            ((unsigned int) c << CHAR_BIT) |
            (unsigned int) d;
}

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

int main(void)
{
    printf("abcd = ");
    bit_print(pack('a', 'b', 'c', 'd'));
    putchar('\n');
    return 0;
}