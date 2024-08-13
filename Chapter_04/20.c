/* Chapter 4 exercise 20 */

/* 다음 코드는 "단축 평가"를 연습할 수 있는 코드이다.

    int a = 0, b = 0, x;

    x = 0 && (a = b = 777);
    printf("%d %d %d\n", a, b, x);
    x = 777 || (a = ++b);
    printf("%d %d %d\n", a, b, x);

 * 어떤 값이 출력되겠는가? 먼저 답을 생각하여 적은 후, 이 코드를 포함하는 프로
 * 그램을 작성하여 확인하여라.
 */

#include <stdio.h>

int main(void)
{
    int a = 0, b = 0, x;

    x = 0 && (a = b = 777);
    printf("%d %d %d\n", a, b, x); // 0 0 0
    x = 777 || (a = ++b);
    printf("%d %d %d\n", a, b, x); // 0 0 1

    return 0;
}