/* Chapter 1 exercise 6 */

/* 대부분의 C 시스템들은 논리적으로 무한한 실수 값들을 제공한다.
 * 연습 문제 5번 프로그램에서 int를 double로 수정하고, printf() 문에서 %d를 %f로 수정하여라.
 * 그 다음 이 프로그램을 수행하면, 실행시간 오류가 발생할까?
 * 대부분의 시스템들에서는 실행시간 오류가 발생하지 않을 것이다.
 * 자신의 시스템에서는 어떻게 되는지 수행시켜 보아라.
 */

#include <stdio.h>

int main(void)
{
   double x, y = 0;

   x = 1 / y;
   printf("x=%f\n", x); /* x = inf */
   return 0;
}