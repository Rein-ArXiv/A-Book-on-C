/* Chapter 1 exercise 15 */

/* (스탠포드 대학의 Donald Knuth가 제안한 문제) 1.6절의 running_sum 프로그램에서
 * 평균값을 계산하기 위해 먼저 숫자의 합을 구하고 더해진 숫자의 개수로 그 합을 나누었다.
 * 다음 프로그램 better_average는 평균값을 더 좋은 방법을 사용하여 계산한 것이다.
 
    #include <stdio.h>

    int main(void)
    {
        int i;
        double x;
        double avg = 0.0;   // a better average
        double navg;        // a naive average
        double sum = 0.0;

        printf("%5s%17s%17s%17s\n%5s%17s%17s%17s\n\n",
            "Count", "Item", "Average", "Naive avg",
            "-----", "----", "-------", "---------");

        for (i=1; scanf("%lf", &x) == 1; ++i){
            avg += (x - avg) / 1;
            sum += x;
            navg = sum / i;
            printf("%5d%17e%17e%17e\n", i, x, avg, navg);
        }
        return 0;
    }

 * 이 프로그램을 수행시켜 보고 원리를 이해하여라. 이 새로운 알고리즘은 평균값을 계산하기 위해
 * 다음 행을 사용하고 있다.
 
    avg += (x - avg) / i;
 
 * 이 알고리즘이 어떻게 평균값을 구하게 되는지 설명하여라. 힌트: 먼저 손으로 단순한 예를 계산해
 * 보아라.
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
        avg += (x - avg) / i;   // avg = avg + (x - avg) / i = (x / i) + (avg - avg / i) = x / i + (i - 1) * avg / i
        sum += x;
        navg = sum / i;
        printf("%5d%17e%17e%17e\n", i, x, avg, navg);
    }

    return 0;
}