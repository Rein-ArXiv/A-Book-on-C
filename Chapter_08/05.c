/* Chapter 8 exercise 5 */

/* 매크로의 몸체에 있는 모든 매개변수가 괄호로 묶여 있다 하더라도 함수만큼 안
 * 전하지는 못하다. 세 인자 중 가장 큰 값을 출력하는 다음과 같은 매크로를 정의
 * 하여라.

    MAX(x, y, z)

 * 이때 원하지 않는 결과를 생성하도록 MAX()에서 사용할 수식을 만들어 보아라.
 */

#include <stdio.h>

#define MAX(x, y, z) ((x) > (y) ? ((x) > (z) ? (x) : (z)) : ((y) > (z) ? (y) : (z)))

int main(void) {
    int x = 0, y = 1, z = 2;
    int max = MAX(x, y, z);
    printf("The maximum value is %d\n", max);
    return 0;
}