/* Chapter 4 exercise 10 */

/* 다음을 포함하는 프로그램을 작성하여, 컴파일러가 이 구문 오류에 대해 어떤 메
 * 시지를 출력하는지 확인해 보아라. 그리고 그 이유를 설명하여라.

    while (++i < LIMIT) do { // Syntax error
        j = 2 * i + 3;
        printf("j = %d\n", j);
    }

    // Many other languages require "do", but not C.

 */

#include <stdio.h>
#define LIMIT   10
int main(void)
{
    int i = 0, j;
    
    while (++i < LIMIT) do { // Syntax error. "error: expected declaration or statement at end of input"
        j = 2 * i + 3;
        printf("j = %d\n", j);
    }

    return 0;
    // Many other languages require "do", but not C.
}