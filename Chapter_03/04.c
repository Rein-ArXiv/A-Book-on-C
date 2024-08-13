/* Chapter 3 exercise 4 */

/* 소수점 이하 부분을 갖는 float 형이나 double 형을 출력할 때, printf() 함수
 * 가 절단을 수행하는지 반올림을 수행하는지를 알아보는 프로그램을 작성하여라.
 * ANSI 표준은 반올림하도록 요구하나, 이것은 시스템에 종속적이다. 사용자 컴퓨
 * 터에서는 어떻게 수행하는가?
 */

#include <stdio.h>

int main(void)
{
    float floatNum = 1.23456789f;
    double doubleNum = 1.234567890123456789;

    printf("Original float number: %.6f\n", floatNum);
    printf("Original double number: %.15lf\n", doubleNum);

    printf("Truncated float number: %.5f\n", floatNum);
    printf("Truncated double number: %.14lf\n", doubleNum);

    return 0;
}

