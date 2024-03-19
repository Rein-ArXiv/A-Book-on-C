/* Chapter 3 exercise 6 */

/* 현재 사용하는 시스템에서 다음 코드를 수행하여라.

    int big_big = 2000000000 + 2000000000;

    printf("%d %u\n", big_big, big_big);

 * 만일 2 바이트 워드를 갖는 컴퓨터를 사용한다면, 2000000000을 32000으로 변경
 * 하여라. 무엇이 출력되는가? 변수 big_big의 형을 int 형이 아닌 unsigned로
 * 선언하면, 출력은 어떻게 변하겠는가?
 */

#include <stdio.h>

int main(void)
{
    int big_big = 2000000000 + 2000000000;
    unsigned int unsigned_big_big = 2000000000 + 2000000000;

    printf("%d %u\n", big_big, big_big);
    printf("%d %u\n", unsigned_big_big, unsigned_big_big);

    return 0;
}