/* Chapter 1 exercise 17 */

/* (고급) 이 연습 문제는 연습 문제 16번에 계속되는 것이다. beter_average 프로그램의
 * 입력으로 위와 같은 큰 숫자가 아닌 평범한 수자를 사용한다면, Average 열과 Naive Avg 열은
 * 같은 것처럼 보인다. 두 열의 값이 달라지는 경우를 찾아보아라. 즉, sum이 오버플로 되지 않을
 * 때도 better_average가 실제로 더 좋은 방법이라는 것을 실험적으로 증명하여라.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, n;
    double x[10000];
    double avg = 0.0;   /* a better average */
    double navg;        /* a naive average */
    double sum = 0.0;

    double avg_check = 0.0;
    double navg_check = 0.0;

    printf("\n%5s%17s%17s%17s%17s%17s\n%5s%17s%17s%17s%17s%17s\n",
        "Count", "Item", "Average", "Naive avg", "Avg precision", "Navg precision",
        "-----", "----", "-------", "---------", "-------------", "--------------");

    n = sizeof(x)/sizeof(x[0]);

    for (i=0; i<n; ++i){
        x[i] = 1.3;
        avg += (x[i] - avg) / (i+1);
        sum += x[i];
    }
    navg = sum / i;

    for (i=0; i<n; ++i){
        avg_check += (x[i] - avg);
        navg_check += (x[i] - navg);
    }

    printf("%5d%17e%17e%17e%17e%17e\n", i, x[0], avg, navg, avg_check, navg_check);
    return 0;
}

