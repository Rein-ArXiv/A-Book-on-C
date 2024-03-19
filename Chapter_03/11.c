/* Chapter 3 exercise 11 */

/* 다음 코드를 실행하여 보고, 왜 가장 큰 정수 값을 출력하는지를 설명하여라.
 
    unsigned long val = -1;

    printf("The biggest number: %lu\n", val);

 * 사용자 컴퓨터에서는 무엇이 출력되는가? 출력되는 결과는 시스템에 따라 다르지
 * 만, 대부분의 시스템에서는 약 40억일 것이다. 설명하여라.
 */


#include <stdio.h>

int main(void)
{
    unsigned long val = -1;

    printf("The biggest number: %lu\n", val); // 4294967295
    return 0;
}