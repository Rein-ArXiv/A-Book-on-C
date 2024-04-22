/* Chapter 5 exercise 7 */

/* 5.12절의 probability() 함수를 사용하여 두 개의 파일을 생성하여라. 여기서 한
 * 파일은 100개의 난수를 가지고, 다른 파일은 1000개의 난수를 갖는다. 모든 수는
 * 0과 1 사이의 값일 것이다. 값이 정말로 무작위 분포를 갖는다면, 난수의 개수가
 * 많아질수록 그 값들의 평균은 0.5에 근접하게 될 것이다. 각 파일에 있는 난수
 * 들의 평균을 계산하여라. 일반적으로 난수 1000개의 평균이 난수 100개의 평균보
 * 다 0.5에 더 가까울 것이다. 과연 그러한가?
 */

#include <stdio.h>
#include "probability.h"

int main(void)
{
    double avg1000 = 0, avg100 = 0;
    
    for (int i = 0; i < 1000; i++) {
        avg1000 += probability();
    }

    for (int i = 0; i < 100; i++) {
        avg100 += probability();
    }

    avg1000 /= 1000.0;
    avg100 /= 100.0;

    printf("Avg 1000: %lf\n", avg1000);
    printf("Avg 100: %lf\n", avg100);
    return 0;
}