/* Chapter 4 exercise 39 */

/* (고급 수준) 연습 문제 38번에서 본 알고리즘에 추가하여, e의 값은 다음과 같은
 * 무한 급수로도 정의될 수 있다.

    e = 1 + 1/1! + 1/2! + 1/3! + 1/4! + ...

 * 이 알고리즘은 효율적이다. 임의의 정확도로 e 값을 계산하기 위해 이 알고리즘을
 * 사용해 보아라.
 */

#include <stdio.h>
#include <math.h>

double part_factorial(int n);

int main(void)
{
    double x = 1.0;
    double real_e = 2.7182818284590452352602874713526624977572;
    int n = 1;
    
    while (real_e - x > 1e-6){
        printf("x: %lf\n", x);
        x += part_factorial(n++);
        printf("Loop count: %d\tError: %lf\n", n, fabs(real_e - x));    
    }
    
    
    printf("Calculated e: %lf\n", x);
    return 0;
}

double part_factorial(int n)
{
    double denominator = 1.0;
    double val = 1.0;

    
    for (int i = n; i > 1; i--){
        denominator *= (double) i;
    }
    val = 1.0 / denominator;
    return val;
}