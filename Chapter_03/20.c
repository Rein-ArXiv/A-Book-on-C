/* Chapter 3 exercise 20 */

/* sqrt() 함수의 인자로 음수를 사용하면 어떤 일이 발생하는가? 어턴 컴파일러는
 * sqrt(-1.0)과 같은 호출에 대해 실행시간 오류를 발생시키고, 어떤 컴파일러는
 * NaN(Not a Number)라는 값을 리턴한다. 사용자 컴퓨터는 어떤 값을 리턴하는가?
 * 다음 코드를 포함하는 프로그램을 작성하여 실행해 보아라.
 
    printf("sqrt(-1.0) = %f\n", sqrt(-1.0));

 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("sqrt(-1.0) = %f\n", sqrt(-1.0));
    return 0;
}
