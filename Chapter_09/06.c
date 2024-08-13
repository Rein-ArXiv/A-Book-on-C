/* Chapter 9 exercise 6 */

/* 다음 프로그램은 "double 형의 인자를 하나 갖고 double 형의 값을 리턴하는 함
 * 수의 포인터" 형을 명명하기 위해 typedef를 사용한다. 먼저 다음 프로그램을 수
 * 행해 보아라.

    #include <stdio.h>
    #include <math.h>

    #define    PI    3.14159

    typedef double  dbl;     // create an abbreviation
    typedef dbl     (*PFDD)(dbl);   // ptr to fct of dbl returning dbl

    int main(void)
    {
        PFDD f = sin, g = cos;

        printf("f(%f) = %f\n", PI, f(PI));
        printf("g(%f) = %f\n", PI, g(PI));
        return 0;
    }

 * 이 프로그램의 두 번째 typedef를 다음으로 대치하여라.
 
    typedef dbl FDD(dbl);   // fct of dbl returning a dbl
    typedef FDD *PFDD;      // ptr to FDD
 
 * 이때도 프로그램은 수행되는가? (수행되어야 한다.) PFDD에 대한 typedef가 어떻
 * 게 동작하는지를 설명하여라.
 */

#include <stdio.h>
#include <math.h>

#define    PI    3.14159

typedef double  dbl;     // create an abbreviation
typedef dbl     (*PFDD)(dbl);   // ptr to fct of dbl returning dbl
// typedef dbl FDD(dbl);   // fct of dbl returning a dbl
// typedef FDD *PFDD;      // ptr to FDD

int main(void)
{
    PFDD f = sin, g = cos;

    printf("f(%f) = %f\n", PI, f(PI));
    printf("g(%f) = %f\n", PI, g(PI));
    return 0;
}

