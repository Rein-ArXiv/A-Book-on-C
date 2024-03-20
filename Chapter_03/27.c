/* Chapter 3 exercise 27 */

/* 다음 코드는 컴퓨터에 종속적이다. 예상 이외의 결과가 출력된다면, 왜 그런지를
 * 설명하여라.

    char c = 0xff;

    if (c == 0xff)
        printf("Truth!\n");
    else
        printf("This needs to be explained!\n");

 */

#include <stdio.h>

int main(void)
{
    char c = 0xff;

    if (c == 0xff)
        printf("Truth!\n");
    else
        printf("This needs to be explained!\n");
    return 0;
}
