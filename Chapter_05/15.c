/* Chapter 5 exercise 15 */

/* 이 연습 문제는 식별자의 유효범위에 관한 것이다. 다음 코드는 어떤 값을 출력하
 * 겠는가? 먼저 답을 작성하고, 프로그램을 작성한 후에 답을 검사해 보아라.

    int a = 1, b = 2, c = 3;

    a += b += ++c;
    printf("%5d%5d%5d\n", a, b, c);
    {
        float b = 4.0;
        int c;

        a += c = 5 * b;
        printf("%5d%5d%5d\n", a, b, c);
    }
    printf("%5d%5d%5d\n", a, b, c);

 */

#include <stdio.h>

int main(void)
{
    int a = 1, b = 2, c = 3;

    a += b += ++c;
    printf("%5d%5d%5d\n", a, b, c);         // 7 6 4
    {
        float b = 4.0;
        int c;

        a += c = 5 * b;
        printf("%5d%5d%5d\n", a, b, c);     // 27 0 20
    }
    printf("%5d%5d%5d\n", a, b, c);         // 27 6 4

    return 0;
}