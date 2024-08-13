/* Chapter 3 exercise 10 */

/* 대부분의 컴퓨터는 정수를 저장하는 데 2의 보수 표현을 사용한다. 이러한 컴퓨터 
 * 에서 -1을 정수적형으로 저장하면 모든 비트는 1이 된다. 사용자 시스템이 이러한
 * 컴퓨터라면, char 형이 signed char 형과 unsigned char 형 중 어느 형과 동
 * 일한지 여부를 결정하는 방법이 있다. 다음을 포함하는 프로그램을 작성하여라.
   
    char c = -1;
    signed char s = -1;
    unsigned char u = -1;

    printf("c = %d s = %d u = %d\n", c, s, u);

 * 각 변수 c, s, u는 비트 패턴 11111111로 메모리에 저장된다. 사용자 시스템에서
 * 는 무엇이 출력되는가? 이것으로 char 형이 어떤 형과 동일하다고 말할 수 있는가?
 * 사용자가 사용하는 ANSI C 컴파일러는 char를 signed나 unsigned char로 변경하
 * 는 옵션을 제공하는가? 그렇다면 그 옵선을 적용하고, 다시 컴파일하여 실행하여라.
 */

#include <stdio.h>

int main(void)
{
    char c = -1;
    signed char s = -1;
    unsigned char u = -1;

    printf("c = %d s = %d u = %d\n", c, s, u);
    return 0;
}