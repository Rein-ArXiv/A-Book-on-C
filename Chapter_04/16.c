/* Chapter 4 exercise 16 */

/* 4.10절 "예제: 부울 변수"에서 부울 함수 값을 표로 출력하는 프로그램을 제시하였
 * 다. 이 프로그램을 실행하고 출력을 조사해 보아라. 32개의 다른 입력에 대해서,
 * 정확히 반(16개)의 우위 값은 1이다. 7개의 부울 변수에 대한 우위 함수의 값을
 * 표로 출력하는 프로그램을 작성하여라. 128개의 다른 입력에 대해서 우위 값이 1
 * 인 개수는 몇 개이겠는가? 일반적인 경우에 대한 정리를 만들고, 이를 증명해 보
 * 아라. (컴퓨터가 특별한 경우를 검사하여 정리를 찾는 데 도움을 줄 수 는 있지만,
 * 일반적으로 증명을 해 주지는 못한다.)
 */

#include <stdio.h>

int main(void)
{
    int b1, b2, b3, b4, b5, b6, b7;     // boolean variables
    int cnt = 0;

    printf("\n%5s%5s%5s%5s%5s%5s%7s%7s%11s\n\n", // headings
        "Cnt", "b1", "b2", "b3", "b4", "b5",
        "fct1", "fct2", "majority");
    for (b1 = 0; b1 <= 1; ++b1)
        for (b2 = 0; b2 <= 1; ++b2)
            for (b3 = 0; b3 <= 1; ++b3)
                for (b4 = 0; b4 <= 1; ++b4)
                    for (b5 = 0; b5 <= 1; ++b5)
                        printf("%5d%5d%5d%5d%5d%5d%6d%7d%9d\n",
                            ++cnt, b1, b2, b3, b4, b5,
                            b1 || b3 || b5, b1 && b2 || b4 && b5,
                            b1 + b2 + b3 + b4 + b5 >= 3);

    putchar('\n');


    cnt = 0;

    printf("\n%5s%5s%5s%5s%5s%5s%5s%5s%11s\n\n", // headings
        "Cnt", "b1", "b2", "b3", "b4", "b5", "b6", "b7", "majority");
    for (b1 = 0; b1 <= 1; ++b1)
        for (b2 = 0; b2 <= 1; ++b2)
            for (b3 = 0; b3 <= 1; ++b3)
                for (b4 = 0; b4 <= 1; ++b4)
                    for (b5 = 0; b5 <= 1; ++b5)
                        for (b6 = 0; b6 <= 1; ++b6)
                            for (b7 = 0; b7 <= 1; ++b7)
                                printf("%5d%5d%5d%5d%5d%5d%5d%5d%9d\n",
                                ++cnt, b1, b2, b3, b4, b5, b6, b7,
                                b1 + b2 + b3 + b4 + b5 + b6 + b7 >= 4);

    putchar('\n');

    return 0;
}