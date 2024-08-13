/* Chapter 4 exercise 37 */

/* (고급 수준) 연습 문제 36번에서 작성한 프로그램을 수정하여, 1부터 입력받은 n
 * 값까지의 모든 정수에 대한 제곱근을 구할 수 있도록 하여라. 매 루프 마다 숫자,
 * 그 숫자의 제곱근, 그 제곱근을 계산하기 위해 반복된 횟수를 출력하여라. (수치
 * 해석 교재를 보면, 왜 Newton-Raphson 방법이 효율적인지를 알 수 있을 것이다.
 * 교재를 보면 이것은 "2차 수렴"한다고 되어 있을 것이다.)
 */

#include <stdio.h>

int main(void)
{
    double n, a;
    double x0, x1 = 1.0;
    int cnt = 0;

    scanf("%lf", &n);

    for (int i=1; i<n; i++){    
        a = i;
        cnt = 0;

        x0 = 0.0;
        x1 = 1.0;
        
        while (x0 != x1){
            x0 = x1;                    // save the current value of x1
            x1 = 0.5 * (x1 + a / x1);   // compute a new value of x1
            printf("Loop count: %d\tError: %lf\n", ++cnt, a - x1 * x1);
        }

        printf("Sqrt of %lf: %lf\n", a, x1);
    }
    return 0;
}