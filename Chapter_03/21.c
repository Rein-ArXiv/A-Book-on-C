/* Chapter 3 exercise 21 */

/* pow(x, x)를 호출할 때 x의 값이 너무 크면 실행시간 오류가 발생되거나,
 * pow(x, x) 값을 printf()로 출력할 경우 Inf 또는 Infinity가 출력된다. 사용
 * 자 컴퓨터에서 다음 문장을 사용하여 실행 오류나 Inf 또는 Infinity를 출력하
 * 지 않는 가장 큰 x 값을 찾아보아라. 힌트: for 문을 사용하여라.
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    float x;
    for (x = 1.0; pow(x, x) != INFINITY; x += 1 )
        printf("pow(%.1f, %.1f) = %.7e\n", x, x, pow(x, x));
    return 0;
}
