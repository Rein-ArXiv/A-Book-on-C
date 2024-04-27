/* Chapter 5 exercise 21 */

/* 전통적인 C에서 변수를 선언할 때, 기억영역 클래스 명시자와 형 명시자를 임의
 * 의 순서대로 기술하는 것이 가능하다. 예를 들어, 다음 두 선언은 같은 의미이다.

    register int i;
    int register i;

 * ANSI C는 기억영역 클래스 명시자를 먼저 쓰도록 되어 있다. 그럼에도 불구하고,
 * 대부분의 ANSI C 컴파일러는 두 가지 다 처리할 것이다. (그렇지 않다면, 전통적
 * 인 C 코드를 컴파일할 수 없다.) 여러분의 컴파일러는 역순으로 기술된 것을 처리
 * 할 수 있는지 검사해 보아라. 
 */

#include <stdio.h>

int main(void)
{
    register int i;
    int register j;

    i = 1;
    j = 0;

    printf("i = %d, j = %d\n", i, j);
    return 0;
}