/* Chapter 4 exercise 32 */

/* 다음은 for 루프의 몸체에서 continue 문이 어떻게 동작하는지를 볼 수 있는 예
 * 제이다. 어떤 값이 출력되는가?

    for (putchar('1'); putchar('2'); putchar('3')) {
        putchar('4');
        continue;
        putchar('5');
    }

 */

#include <stdio.h>

int main(void)
{
    for (putchar('1'); putchar('2'); putchar('3')) {
        putchar('4');
        continue;
        putchar('5');
    }

    return 0;
}