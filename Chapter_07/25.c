/* Chapter 7 exercise 25 */

/* pack() 함수를 산술 연산만을 사용하여 작성하여라.
 */

#include <stdio.h>
#include <limits.h>

int pack(char a, char b, char c, char d)
{
    int CHAR_BIT_LEFT = 256;
    unsigned int p = (a * (CHAR_BIT_LEFT * CHAR_BIT_LEFT * CHAR_BIT_LEFT)) +
            (b * (CHAR_BIT_LEFT * CHAR_BIT_LEFT)) +
            (c * (CHAR_BIT_LEFT)) +
            (d);
    return p;
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