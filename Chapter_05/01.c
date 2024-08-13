/* Chapter 5 exercise 1 */

/* x^n(x의 n승)을 계산하는 double power(double x, int n) 함수를 작성하여라.
 * 그리고, 3.5^7이 6433.9296875인지 확인해 보아라.
 */

#include <stdio.h>

double power(double x, int n);

int main(void)
{
    double x = 3.5;
    int n = 7;

    printf("3.5 ^ 7 = %lf\n", power(x, n));

	return 0;
}

double power(double x, int n)
{
    double val = 1.0;
    for (int i=n; i>0; i--){
        val *= x;
    }
    return val;
}