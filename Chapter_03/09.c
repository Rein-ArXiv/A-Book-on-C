/* Chapter 3 exercise 9 */

/* 두 함수 tan(sin(x))와 sin(tan(x))를 원점에서 Taylor 전개하면 처음 7항까
 * 지는 같다. (Maple이나 Mathematica를 이용하면 쉽게 알 수 있다.) 이것은 원점
 * 에서 두 함수의 차가 9에 가까움을 뜻한다. 다음 프로그램을 실행시켜 보아라.

    #include <math.h>
    #include <stdio.h>

    double f(double x);

    int main(void)
    {
        double x;

        for (x = -0.25; x <= +0.25; x += .01)
        printf("f(%+.2f) = %+.15f\n", x, f(x));
        return 0;
    }

    double f(double x)
    {
        return (tan(sin(x)) - sin(tan(x)));
    }

 * 프로그램의 출력을 보고 원점 근처에서 0에 가까움을 확인해 보아라. 출력 형식에
 * 서 + 기호를 제거한 후 수행해 보아라. 결과가 잘 정렬되지 않음을 볼 수 있을 것
 * 이다.
 */

#include <math.h>
#include <stdio.h>

double f(double x);

int main(void)
{
    double x;

    for (x = -0.25; x <= +0.25; x += .01)
        printf("f(%+.2f) = %+.15f\n", x, f(x));
    return 0;
}

double f(double x)
{
    return (tan(sin(x)) - sin(tan(x)));
}