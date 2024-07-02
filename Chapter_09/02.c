/* Chapter 9 exercise 2 */

/* 어떤 상황에서는 typedef를 #define으로 대치할 수 없다. 다음 프로그램을 보자.

    typedef float DOLLARS;

    int main(void)
    {
        DOLLARS amount = 100.00, interest = 0.07 * amount;

        {                           // new block
            float DOLLARS;

            DOLLARS = amount + interest;
            printf("DOLLARS = %.2f\n", DOLLARS);
        }
        return 0;
    }

 * 이 프로그램을 수행해 보아라. 그리고, typedef를 다음으로 대치해 보아라.

    #define DOLLARS float

 * 이제 프로그램은 컴파일되지 않을 것이다. 왜 typedef를 사용하면 되고, #define
 * 을 사용하면 안 되는지 설명하여라.
 */

#include <stdio.h>

#define DOLLARS float;

//typedef float DOLLARS;

int main(void)
{
    DOLLARS amount = 100.00, interest = 0.07 * amount;

    {                           // new block
        float DOLLARS;          // #define DOLLARS float -> float float, typedef float DOLLARS -> float DOLLARS (variables name)

        DOLLARS = amount + interest;
        printf("DOLLARS = %.2f\n", DOLLARS);
    }
    return 0;
}
