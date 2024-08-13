/* Chapter 3 exercise 19 */

/* 수학에서 e와 pi값은 잘 알려져 있다. e는 자연로그의 기수이고, pi는 원주율이다.
 * 이때 e^pi와 pi^e의 값 중 어느 것이 더 큰가? 이것은 해석학을 수강하는 학생들에게
 * 는 간단한 문제이다. 그러나 e와 pi를 전혀 알지 못하고, 해석학에 대해서도 알지
 * 못한다 하더라도, 이 문제에 답할 수 있다.
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double ePi = pow(M_E, M_PI) ;   // e^pi
    double piE = pow(M_PI, M_E);    // pi^e
    
    printf("e^pi = %.7f\npi^e = %.7f\n", ePi, piE);
    return 0;
}
