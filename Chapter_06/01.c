/* Chapter 6 exercise 1 */

/* 다음 코드를 실행시키면 4개의 값이 출력된다. 이것들 중 같은 값들은 몇 개인가?
 * 답에 대해 설명하여라.

    char *format = "%p %d %d %d\n";
    int i = 3;
    int *p = &i;

    printf(format, p, *p + 7, 3 * **&p + 1, 5 * (p - (p - 2)));

 */

#include <stdio.h>

int main(void)
{
    char *format = "%p %d %d %d\n";
    int i = 3;
    int *p = &i;

    printf(format, p, *p + 7, 3 * **&p + 1, 5 * (p - (p - 2)));
    return 0;
}