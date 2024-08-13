/* Chapter 3 exercise 25 */

/* 수학 코드에서 fabs() 대신 abs()를 사용하면 이상한 결과를 얻을 것이다. 다음
 * 프로그램을 수행해 보아라.

    #include <math.h>   // for fabs())
    #include <stdio.h>
    #include <stdlib.h> // foro abs()

    int main(void)
    {
        double x = -2.357;
        
        printf(" abs(x) = %e\n", abs(x)); // wrong!
        printf("fabs(x) = %e\n", fabs(x));
        return 0;
    }

 * 어떤 컴파일러는 경고 메시지를 내지만, 어떤 것은 내지 않을 것이다. 사용자 컴
 * 퓨터에서 컴파일할 때 경고 메시지를 내는가? 작은 프로그램에서는 이와 같은 오
 * 류를 쉽게 찾을 수 있지만, 큰 프로그램에서는 찾기가 매우 힘들 것이다.
 */

#include <math.h>   // for fabs())
#include <stdio.h>
#include <stdlib.h> // foro abs()

int main(void)
{
    double x = -2.357;
    
    printf(" abs(x) = %e\n", abs(x)); // wrong!
    printf("fabs(x) = %e\n", fabs(x));
    return 0;
}

