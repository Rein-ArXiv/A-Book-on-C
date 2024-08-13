/* Chapter 5 exercise 8 */

/* x에 대한 2차 다항식은 다음과 같다.

    ax^2 + bx + c

 * 임의의 2차 다항식의 값을 계산하는 다음과 같은 형태의 함수를 작성하여라.

    double f(double a, double b, double c, double x)
    {
        .....

 * 곱셈 연산의 수를 최소화하기 위해 다음 식을 이용하여라.

    (ax + b)x + c = ax^2 + bx + c

 * 이 함수를 사용하여 [0, 3] 구간에서 다항식 x^2 - 3x + 2의 그래프를 점으로 그려
 * 서 파일에 저장하는 프로그램을 작성하여라. 변수 x는 0부터 3까지 0.1 간격으로
 * 값을 가진다. 그 파일을 검사하여, 다항식 근이 어디에 있는지 찾아보아라.
 */

#include <stdio.h>

double f(double a, double b, double c, double x);

int main(void)
{
    double x, y;
    FILE *fp = fopen("graph.txt", "w");

    for (x = 0.0; x <= 3.0; x += 0.1) {
        y = f(1.0, -3.0, 2.0, x);
        fprintf(fp, "%0.1f %0.1f\n", x, y);
    }

    fclose(fp);
    return 0;
}

double f(double a, double b, double c, double x)
{
    double val = (a * x + b) * x + c;
    return val;
}