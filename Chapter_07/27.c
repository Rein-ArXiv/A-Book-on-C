/* Chapter 7 exercise 27 */

/* 'abc'와 같은 다중문자 문자 상수의 저장 방법은 시스템에 따라 다르다. 프로그
 * 래머는 때때로 "abc"를 'abc' 라고 쓸 수 있기 때문에, 어떤 컴파일러는 다중문
 * 자 상수가 사용되면 비록 그 사용이 타당하다 해도 경고 메시지를 생성한다. 사
 * 용하고 있는 시스템에서는 어떻게 되는가? 다음 코드를 수행해 보아라.
 
    int c = 'abc';

    printf("'abc' = ");
    bit_print(c);
    printf("\n");

 * Sun 워크스테이션에서 실행했을 때의 결과는 다음과 같다.

    'abc' = 00000000 01100011 01100010 01100001
 
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

int main(void){
    int c = 'abc';

    printf("'abc' = ");
    bit_print(c);
    printf("\n");
}