/* Chapter 7 exercise 10 */

/* 만일 4바이트 워드 컴퓨터를 사용하고 있다면, bit_print() 함수를 사용하여
 * 다중 바이트 문자 'abc'가 어떻게 저장되는지를 알아보는 프로그램을 작성하여
 * 라. 2 바이트 워드 컴퓨터에서는 단지 두 문자만이 하나의 다중 바이트 문자로 저
 * 장될 수 있다. 그 경우에는 'ab'를 사용하여라.
 */

#include <stdio.h>
#include <limits.h>

void bit_print(char a)
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


int main(void){
    char c = 'abc';     // Equal to char c = 'c'
    bit_print(c);
    return 0;
}