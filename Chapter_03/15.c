/* Chapter 3 exercise 15 */

/* 먼저 다음 코드의 출력을 생각하여 적어보고, 프로그램을 작성하여 답을 확인해
 * 보아라.

    char c = 'A';
    printf("sizeof(c)       = %u\n", sizeof(c));
    
 */


#include <stdio.h>

int main(void)
{
    char c = 'A';
    printf("sizeof(c)           = %u\n", sizeof(c));
    printf("sizeof('A')         = %u\n", sizeof('A'));
    printf("sizeof(c + c)       = %u\n", sizeof(c + c));
    printf("sizeof(c = 'A')     = %u\n", sizeof(c = 'A'));
    return 0;
}