/* Chapter 7 exercise 8 */

/* bit_print() 함수를 사용하여 n = 0, 1, 2, ..., 32에 대해서 2^n과 2^n - 1의 이진 
 * 수 표현을 표로 출력하는 프로그램을 작성하여라. 2 바이트 워드 컴퓨터를 사용한
 * 다면, 프로그램의 출력은 다음과 같을 것이다.

    0: 00000000 00000001    00000000 00000000
    1: 00000000 00000010    00000000 00000001
    2: 00000000 00000100    00000000 00000011
    .....
   15: 10000000 00000000    01111111 11111111
    .....

 * 이것이 끝나면, n = 0, 1, ..., 7에 대해서 10^n과 10^n - 1을 위와 같은 표 형태로
 * 직접 써보아라. 이때는 각 수를 10진수로 작성한다. 두 표간의 유사점을 발견할
 * 수 있는가? 힌트: 다음 코드를 사용하여라.

    int i, power = 1;

    for (i = 0; i < 32; ++i){
        printf("%2d : ")
    }

 */

#include <stdio.h>
#include <limits.h>

void bit_print(int a);

int main(void){
    int i, j, power = 1, ten = 10;

    for (i = 0; i < 32; ++i){
        printf("%2d : ", i);
        bit_print(power);
        printf(" ");
        bit_print(power - 1);
        putchar('\n');
        power *= 2;
    }

    putchar('\n');

    for (i = 0, power = 1; i < 8; ++i){
        printf("%2d : ", i);
        for(j = 0; j < 7 - i; ++j){ 
            putchar('0');
        }
        
        printf("%d\t", power);
        
        for(j = 0; j < 7 - i; ++j){ 
            putchar('0');
        }
        if (i != 0){
            putchar('0');
        }

        printf("%d\n", power - 1);
        power *= 10;
    }

    return 0;
}

void bit_print(int a)
{
    int i;
    int n = sizeof(int) * CHAR_BIT;
    int mask = 1 << (n - 1);

    
    for (i = 1; i <= n; i++){
        putchar(((a & mask) == 0) ? '0' : '1');

        a <<= 1;

        if (i % CHAR_BIT == 0 && i < n)
            putchar(' ');
    }
    putchar('\t');
}