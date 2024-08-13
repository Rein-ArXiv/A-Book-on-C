/* Chapter 9 exercise 1 */

/* 어떤 상황에서는 typedef를 #define으로 대치할 수 있다. 다음 예제를 보자.

    typedef float DOLLARS;

    int main(void)
    {
        DOLLARS amount = 100.00, interest = 0.07 * amount;

        printf("DOLLARS = %.2f\n", amount + interest);
        return 0;
    }

 * 이 프로그램을 실행해 보아라. 그리고, typedef를 다음으로 대치하여라.

    #define DOLLARS float

 * 수정된 프로그램을 다시 컴파일하고 수행해 보아라. 이전과 동일한 결과를 내는가?
 */

#include <stdio.h>

#define DOLLARS float

//typedef float DOLLARS;

int main(void)
{
    DOLLARS amount = 100.00, interest = 0.07 * amount;

    printf("DOLLARS = %.2f\n", amount + interest);
    return 0;
}