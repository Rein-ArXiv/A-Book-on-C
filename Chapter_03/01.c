/* Chapter 3 exercise 1 */

/* 모든 실수를 컴퓨터에서 표현할 수 있는 것은 아니다. 따라서 컴퓨터에서 이용 가능한
 * 실수는 매우 일부분이다. 이러한 예로서 다음 코드를 수행시키면, 두 개의 동일한 수를
 * 출력할 것이다.

    double x = 123.45123451234512345;
    double y = 123.45123451234512300; // last two digits zero
    printf("%.17f   %17.f\n", x, y);

 * 다른 수가 출력되게 하려면 y 값이 끝에서부터 몇 개가 0으로 끝나야 하는가?
 * 설명해 보아라.
 */

#include <stdio.h>

int main(void)
{
    double x = 123.45123451234512345;
    double y = 123.45123451234512300; // last two digits zero
    printf("%.17f   %.17f\n", x, y);
    
    double diff_x = 123.45123451234510000;
    double diff_y = 123.45123451234512345;
    printf("%.17f   %.17f\n", diff_x, diff_y);
    return 0;
}
