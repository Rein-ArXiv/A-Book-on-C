/* Chapter 9 exercise 27 */

/* 이 연습 문제는 =와 ==의 피연산자로 구조체를 사용하는 경우에 대해 살펴본다.
 * a와 b가 같은 구조체형의 변수라고 하자. 이때 수식 a = b는 유효하지만, 수식 a
 * == b는 유효하지 않다. 즉, == 연산자의 피연산자는 구조체가 될 수 없다. (초보
 * 프로그래머는 이런 차이를 종종 간과한다. 이를 검사하기 위해 수식 a == b를 포
 * 함하는 프로그램을 작성하고, 컴파일러가 어떤 메시지를 내는지 컴파일해 보아라.
 */

#include <stdio.h>

typedef struct complex {
    double re;
    double im;
} complex;


int main(void)
{
    complex a, b;
    a.re = 1.0;
    a.im = 2.0;

    b.re = 3.0;
    b.im = 4.0;

    printf("Original a =    %.1lf + %.1lfi\t b = %.1lf + %.1lfi\n", a.re, a.im, b.re, b.im);

    a = b;

    printf("After a =       %.1lf + %.1lfi\t b = %.1lf + %.1lfi\n", a.re, a.im, b.re, b.im);
   
    
    /*
    if (a == b){                    // error: invalid operands to binary == (have 'complex' and 'complex')
        printf("Struct a = b\n");
    }
    else{
        printf("Struct a != b\n");
    }
    */
    
    return 0;
}