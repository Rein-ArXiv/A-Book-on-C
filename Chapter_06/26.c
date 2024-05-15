/* Chpater 6 exercise 26 */

/* 비록 나쁜 프로그램 습관이지만, 전통적인 C에서는 문자열 상수의 내용을 변경할
 * 수 있게 하였다. ANSI C는 프로그래머가 문자열 상수를 변경할 수 없도록 규정
 * 하고 있다. 그러나, 이것의 적용은 컴파일러에 따라 다르다. 다음 코드를 보자.
 
    char *p = "abc";

    *p = 'X';           // illegal?
    printf("%s\n", p);  // Xbc gets printed?
 
 * 어느 컴파일러는 실행시간 오류를 일으키는 데 반하여, 어떤 컴파일러는 오류 없
 * 이 실행될 것이다. 각자의 시스템은 어떤지 실험해 보아라.
 */

#include <stdio.h>

int main(void)
{
    char *p = "abc";

    *p = 'X';           // illegal?
    printf("%s\n", p);  // Xbc gets printed?
    return 0;
}