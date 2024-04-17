/* Chapter 4 exercise 35 */

/* ANSI C에서 레이블은 자신의 이름 영역을 가지고 있지만, 전통적인 C에서는 그
 * 렇지 못하다. 비록 좋은 프로그래밍 방법은 아니지만, ANSI C에서는 하나의 식별
 * 자를 변수와 레이블로 동시에 사용할 수 있다. 다음 코드를 포함하는 프로그램을
 * 작성하고, ANSI C 컴파일러로 실행해 보아라.

    int L = -3;     // L is a variable

    if (L < 0)
        goto L;
    printf("L = %d\n", L);
    L: printf("Exiting label test!\n");     // L is a label

 * 만일 전통적인 C 컴파일러를 사용할 수 있다면, 이 프로그램이 컴파일되는지 검
 * 사해 보아라.
 */

#include <stdio.h>

int main(void)
{
    int L = -3;     // L is a variable

    if (L < 0)
        goto L;
    printf("L = %d\n", L);
    L: printf("Exiting label test!\n");     // L is a label

    return 0;
}