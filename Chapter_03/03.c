/* Chapter 3 exercise 3 */

/* sin(), cos(), tan()에 대한 삼각함수 값을 표로 출력하는 프로그램을 작성하여라.
 * 표에서 각도는 0에서 pi까지 20단계로 한다.
 */

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define STEP 20

int main(void){
    double angle;
    
    printf("Angle\tSin\tCos\tTan\n");
    printf("-----\t---\t---\t---\n");
    
    for(int i = 0; i <= STEP; i++)
    {
        angle = M_PI * i / STEP;    
        printf("%.2f\t%.4f\t%.4f\t%.4f\n", angle, sin(angle), cos(angle), tan(angle));
    }
    return 0;
}