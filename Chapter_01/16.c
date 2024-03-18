/* Chapter 1 exercise 16 */

/* 이 연습 문제는 연습 문제 15번의 better_average 프로그램에서 sum이 컴퓨터에서
 * 표현 가능한 값보다 더 큰 값을 갖리 때 어떤 일이 발생하는지를 알아본다.
 * (double 형이 가질 수 있는 값에 대한 상세한 것은 3.6절 "부동형"을 참조하여라.)
 * data라는 파일을 만들어 다음 숫자들을 그 파일에 써넣어라.
 
    1e308 1 1e308 1 1e308

 * 그 다음 data 파일을 better_average의 입력 파일로 재지정한 후 수행시켜 보아라.
 * 이 알고리즘의 장점을 알겠는가?
 */

#include <stdio.h>

int main(void)
{
    int i;
    double x;
    double avg = 0.0;   /* a better average */
    double navg;        /* a naive average */
    double sum = 0.0;

    printf("%5s%17s%17s%17s\n%5s%17s%17s%17s\n\n",
        "Count", "Item", "Average", "Naive avg",
        "-----", "----", "-------", "---------");

    for (i=1; scanf("%lf", &x) == 1; ++i){
        avg += (x - avg) / i;   // No overflow
        sum += x;
        navg = sum / i;         // overflow
        printf("%5d%17e%17e%17e\n", i, x, avg, navg);
    }

    return 0;
}