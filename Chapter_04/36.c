/* Chapter 4 exercise 36 */

/* (고급 수준) a를 양의 실수라 하고, 실수 x_i의 수열을 다음과 같이 정의하자.
 
    x_0 = 1, x_{i+1} = {1 \over 2}(x_i + {a \over x})   for i = 0, 1, 2, ...

 * 이 식은 수학적으로 i가 inf로 접근할 때 다음과 같음을 의미한다.

    x_i \rightarrow \sqrt(a)

 * 이 알고리즘은 수치 해석의 Newton-Raphson 방법으로부터 유도된다. a의 값을
 * 읽어 들여, 이 알고리즘을 사용하여 a의 제곱근을 계산하는 프로그램을 작성하여
 * 라. 이 알고리즘은 매우 효율적이다. (그러나 표준 라이브러리의 sqrt() 함수는
 * 이 알고리즘을 사용하지 않는다.) x0과 x1은 double 형으로 선언하고, x1은 1로
 * 초기화하여라. 루프 내부에서 다음 코드를 사용하여라.
 
    x0 = x1;                    // save the current value of x1
    x1 = 0.5 * (x1 + a / x1);   // compute a new value of x1
  
 * 루프의 몸체는 x0과 x1이 같지 않는 한 계속 실행되어야 한다. 매 루프마다 실행
 * 횟수와 x1의 값(a의 제곱근에 수렴함)과 a - x1 * x1(정확성에 대한 확인용)의 값
 * 을 출력하여라.
 */

#include <stdio.h>

int main(void)
{
    double a;
    double x0, x1 = 1.0f;
    int cnt = 0;

    scanf("%lf", &a);

    while (x0 != x1){
        x0 = x1;                    // save the current value of x1
        x1 = 0.5 * (x1 + a / x1);   // compute a new value of x1
        printf("Loop count: %d\tError: %lf\n", ++cnt, a - x1 * x1);
    }

    printf("Sqrt of %lf: %lf\n", a, x1);

    return 0;
}