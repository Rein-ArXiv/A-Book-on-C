/* Chapter 3 exercise 18 */

/* ANSI C는 이진 부동소수점 산술식을 위한 IEEE 표준화(ANSI/IEEE Std
 * 754-1985)의 권고를 따르도록 제안하고 있다. 사용자 시스템은 이러한
 * 권고를 따르고 있는?가 부동형 변수에 해당 값의 범위를 초과하는 값을
 * 저장할 때 어떤 일이 발생하는가를 검사해 보자. 다음 코드를 포함하는
 * 프로그램을 작성하여라.

    float x = 1e+307;   // big
    float y = x * x;    // too big
    
    printf("x = %e  y = %e\n", x, y);
    
 * 어떤 값이 출력되는가? 만일 y 값으로 Inf나 Infinity를 출력한다면,
 * 사용자 시스템은 ANSI/IEEE Std 754-1985를 따르고 있는 것이다.
 */


#include <stdio.h>

int main(void)
{
    float x = 1e+307;   // big
    float y = x * x;    // too big
    
    printf("x = %e  y = %e\n", x, y);
    return 0;
}
