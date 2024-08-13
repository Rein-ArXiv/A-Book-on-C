/* Chapter 6 exercise 7 */

/* 만일 주소를 16진수 대신 10진수로 출력하여 보기 원한다면, 주소를 unsigned
 * long으로 캐스트하고 %lu 형식을 사용하는 것이 안전한 방법이다. 연습 문제 6번
 * 의 printf() 문을 다음과 같이 수정하여 실행시켜 보아라.

        printf("%s%lu\n%s%lu\n%s%lu\n",
                "&a = ", (unsigned long) &a,
                "&b = ", (unsigned long) &b,
                "&c = ", (unsigned long) &c);

 */

#include <stdio.h>

int main(void)
{
    int a = 1, b = 2, c = 3;

    printf("%s%lu\n%s%lu\n%s%lu\n",
        "&a = ", (unsigned long) &a,
        "&b = ", (unsigned long) &b,
        "&c = ", (unsigned long) &c);

    return 0;
}



