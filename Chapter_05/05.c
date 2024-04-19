/* Chapter 5 exercise 5 */

/* 이번 연습 문제는 함수 선언에 관한 것이다. 여기서는 수학 라이브러리에 있는
 * pow() 함수를 사용할 것인데, math.h 헤더 파일을 포함시키는 대신 함수 선언을
 * 직접 할 것이다. 다음 프로그램을 수행해 보아라.

    #include <stdio.h>

    double pow(double, double);

    int main(void)
    {
        printf("pow(2.0, 3.0) = %g\n", pow(2.0, 3.0));
        return 0;
    }

 * 그 다음 printf() 문을 다음과 같이 수정한 후 다시 수행해 보아라.
    
    printf("pow(2, 3) = %g\n", pow(2, 3))

 * pow() 함수의 인자의 형이 double이 아니라 int라도 정확한 결과가 나오는가?
 * 정확한 결과가 나와야 한다. 컴파일러는 double 형의 인자가 필요하다는 것을 알
 * 고 있기 때문에, 제공되는 값을 정확한 형태로 변환시킬 수 있다. 다음으로 함수
 * 원형을 다음과 같이 수정하여 수행해 보아라.
 
    double pow();   // traditional style

 * 어떤 일이 발생하는가? 마지막으로 pow() 함수의 선언을 완전히 제거하여라. 프
 * 로그램이 정확히 수행되지는 않을지라도 컴파일은 될 것이다. 그러한가? C 시스
 * 템이 라이브러리에 있는 함수들의 목적 코드를 제공하지만, 사용하고자 하는 함수
 * 의 정확한 함수 원형을 제공하는 것은 프로그래머의 책임이다.
 */

#include <stdio.h>

double pow(double, double);
//double pow();

int main(void)
{
    printf("pow(2.0, 3.0) = %g\n", pow(2.0, 3.0));
    printf("pow(2, 3) = %g\n", pow(2, 3));

    return 0;
}

