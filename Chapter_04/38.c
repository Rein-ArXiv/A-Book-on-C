/* Chapter 4 exercise 38 */

/* (고급 수준) 자연 로그의 밑수인 상수 e는 다음과 같이 41개의 유효숫자로 주어진
 * 다.

    e = 2.71828 18284 59045 23526 02874 71352 66249 77572

 * 그리고 다음과 같은 수열을 정의하자.

    x_n = (1 + {1 \over n})^n       for n = 1, 2, ...

 * 이것은 수학적으로 n->inf 일 때, x_n -> e이다. 이 알고리즘을 사용하여 어떻게 
 * 임의의 정확도로 e 값을 계산할 수 있는지를 연구해보아라. 이 알고리즘은 효율적
 * 이지 않음을 알 수 있다. (연습문제 36번을 참조하여라.)
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double x;
    double real_e = 2.7182818284590452352602874713526624977572;
    int n = 1;
    
    while (real_e != x){
        x = pow((1.0 + 1.0/n), n);
        n++;
    }
    printf("Loop count: %d\tError: %lf\n", n++, fabs(real_e - x));
    printf("Calculated e: %lf\n", x);
    return 0;
}