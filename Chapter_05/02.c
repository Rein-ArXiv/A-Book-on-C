/* Chapter 5 exercise 2 */

/* 라이브러리 함수 sqrt()를 사용하여 정수 인자 k의 네제곱근을 계산하는 함수를
 * 작성하여라. 리턴되는 값은 double이어야 한다. 또한 이 함수를 사용하여 여러
 * 값을 표 형식으로 출력하는 프로그램을 작성하여라.
 */

#include <stdio.h>
#include <math.h>

double fort(int x);

int main(void)
{
    int k;

    printf("Input number: ");
    scanf("%d", &k);

    printf("%10s%10s%10s%10s\n\n", "Number", "Square", "Fourth", "Sixteen");
    printf("%10d%10.4lf%10.4lf%10.4lf\n", k, sqrt((double) k), fort(k), fort((int) fort(k)));

	return 0;
}

double fort(int x)
{
    double val = x;
    val = sqrt(sqrt(val));
    return val;
}