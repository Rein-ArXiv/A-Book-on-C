/* Chapter 3 exercise 7*/

/* 다음 코드를 주의 깊게 살펴보아라.

    printf("Why is 21 + 31 equal to %d?\n", 2l + 3l);

 * 4 바이트의 int 컴퓨터에서는 다음과 같은 결과를 얻었다.
    
    Why is 21 + 31 equal to 5?

 * 어떻게 이런 출력이 나왔는지를 설명하여라.
 */

#include <stdio.h>

int main(void)
{
    printf("Why is 21 + 31 equal to %d?\n", 21 + 31); // 21 + 31, number 1 used.
    printf("Why is 21 + 31 equal to %d?\n", 2l + 3l); // 2l + 3l, alphabet l used.
    return 0;
}