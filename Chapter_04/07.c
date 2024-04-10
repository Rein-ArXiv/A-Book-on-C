/* Chapter 4 exercise 7 */

/* 다음 코드의 실행 결과를 설명하여라.

    int i;
    .....
    while (i = 2) {
        printf("Some even numbers : %d %d %d\n", i, i + 2, i + 4);
        i = 0;
    }

 * 이 코드와 다음 코드를 비교해 보아라.

    int i;
    .....
    if (i = 2)
        printf("Some even numbers : %d %d %d\n", i, i + 2, i + 4);
    
    위의 두 코드는 논리적으로 잘못되어 있다. 두 코드 중 하나는 실행시간에 잘못된
    부분을 쉽게 찾을 수 있지만, 다른 코드는 잘못된 부분을 쉽게 찾을 수 없을 것이
    다. 왜 그런지를 설명해 보아라.
    
 */

#include <stdio.h>

int main(void)
{
    int i;

    while (i = 2) { // (i == 2)
        printf("Some even numbers : %d %d %d\n", i, i + 2, i + 4);
        i = 0;
    }

    if (i = 2) // (i == 2)
        printf("Some even numbers : %d %d %d\n", i, i + 2, i + 4);


    return 0;
}