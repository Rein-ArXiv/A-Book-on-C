/* Chapter 3 exercise 22 */

/* 전통적인 C에서 float은 double로 자동 승격된다. ANSI C에서는 수학 수식에
 * 서 float을 double로 승격할 수 있지만, 요구사항은 아니다. 대부분의 ANSI C
 * 컴파일러는 수식에서 확장 없이 float을 사용하는 것으로 조사되었다. 다음 코드
 * 를 사용하여 사용자 시스템에서는 어떻게 동작하는 지를 확인하여 보아라.
 
    float x = 1.0, y = 2.0;

    printf("%s%u\n%s%u\n%s%u\n",
            "sizeof(float) = ", sizeof(float),
            "sizeof(double) = ", sizeof(double),
            "sizeof(x + y) = ", sizeof(x + y));

 */

#include <stdio.h>

int main(void)
{
    float x = 1.0, y = 2.0;

    printf("%s%lu\n%s%lu\n%s%lu\n",
            "sizeof(float) = ", sizeof(float),
            "sizeof(double) = ", sizeof(double),
            "sizeof(x + y) = ", sizeof(x + y));

    return 0;
}

