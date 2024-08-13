/* Chapter 3 exercise 2 */

/* 다음 수학 공식은 모든 x에 대해서 만족한다.
 
    $sin^2 (x) + cos^2(x) = 1$

 * 다음 프로그램을 수행하여 컴퓨터에서 이것이 항상 만족하는지 검사해 보아라.
 
    #include <math.h>
    #include <stdio.h>

    int main(void)
    {
        double two_pi = 2.0 * M_PI; // in math.h
        double h = 0.1;             // step size
        double x;

        for (x = 0.0; x < two_pi; x += h)
            printf("%5.1f: %.15e\n",
                x, sin(x) * sin(x) + cos(x) * cos(x));
        return 0;
    } 

 * 이 코드에서 %.15e를 %.15f로 수정하여 수행하면 어떻게 되겠는가? 설명하여라.
 */

#include <math.h>
#include <stdio.h>

int main(void)
{
    double two_pi = 2.0 * M_PI; /* in math.h */
    double h = 0.1;             /* step size */
    double x;

    for (x = 0.0; x < two_pi; x += h)
        printf("%5.1f: %.15e\n", /* If changed to %.15f, all numbers are 1.000...0 */
                x, sin(x) * sin(x) + cos(x) * cos(x));
    return 0;
}
