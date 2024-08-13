/* Chapter 7 exercise 9 */

/* 이 장의 표들에 있는 이진 표현 중 어떤 것은 오류를 검사하기가 용이하나 일부
 * 는 그렇지 못하다. bit_print() 함수를 이용하여 좀더 어려운 표현을 검사해 보
 * 아라.
 */

#include <stdio.h>
#include <limits.h>

void bit_print_float(float a);

int main(void)
{
    float a = 0.25f;
    float b = 1.0f / 9.0f;
    bit_print_float(a);
    bit_print_float(b);
}

void bit_print_float(float f)
{
    int i;
    int n = sizeof(float) * CHAR_BIT;
    unsigned int mask = 1 << (n - 1);
    unsigned int *p = (unsigned int *)&f;
    unsigned int val = *p;
    
    for (i = 1; i <= n; i++){
        putchar(((val & mask) == 0) ? '0' : '1');

        val <<= 1;

        if (i % CHAR_BIT == 0 && i < n)
            putchar(' ');
    }
    putchar('\n');
}