/* Chapter 4 exercise 25 */

/* 부울 함수의 진리표는 변수들의 모든 가능한 값과 각 경우에 대한 부울 함수의
 * 값으로 구성된 표이다. 4.10절 "예제: 부울 변수"에서 우위 함수와 두 개의 다른
 * 함수에 대한 진리표를 만들었다. 그 표에서는 참과 거짓을 각각 1과 0으로 나타내
 * 었다. 다음 부울 함수에 대한 진리표를 각각 작성하여라.
 
    (a) b1 || b2 || b3 || b4
    (b) b1 && b2 && b3 && b4
    (c) !(!b1 || b2) && (!b3 || b4)
 
 * 여기서 만드는 표에서는 참과 거짓을 나타내기 위해 각각 T와 F를 사용하여라.
 * 힌트: BOOLEX를 정의하기 위해 #define을 사용하고, 임의의 BOOLEX에 대해 연
 * 산을 하는 프로그램을 작성하여라.
 */

#include <stdio.h>

#define T 1
#define F 0

int fct1(int b1, int b2, int b3, int b4) {
    return b1 || b2 || b3 || b4;
}

int fct2(int b1, int b2, int b3, int b4) {
    return b1 && b2 && b3 && b4;
}

int fct3(int b1, int b2, int b3, int b4) {
    return !!(!b1 || b2) && (!b3 || b4); // 괄호 추가
}

int main(void) {
    int b1, b2, b3, b4;
    unsigned int cnt = 0; // 더 큰 범위를 대비하여 unsigned int 사용

    printf("\n%5s%5s%5s%5s%5s%7s%7s%7s\n\n",
           "Cnt", "b1", "b2", "b3", "b4", "fct1", "fct2", "fct3");

    for (b1 = 0; b1 <= 1; ++b1) {
        for (b2 = 0; b2 <= 1; ++b2) {
            for (b3 = 0; b3 <= 1; ++b3) {
                for (b4 = 0; b4 <= 1; ++b4) {
                    ++cnt;
                    printf("%5d%5d%5d%5d%5d%7d%7d%7d\n",
                           cnt, b1, b2, b3, b4,
                           fct1(b1, b2, b3, b4),
                           fct2(b1, b2, b3, b4),
                           fct3(b1, b2, b3, b4));
                }
            }
        }
    }

    return 0;
}