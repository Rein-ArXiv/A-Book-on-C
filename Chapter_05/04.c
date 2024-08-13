/* Chapter 5 exercise 4 */

/* 전통적인 C의 일반적인 함수 정의 형태는 다음과 같다.

    type function_name(parameter list)
    declarations of the parameters
    {
        declarations
        statements
    }

 * 5.1절 "함수 정의"를 참고하여, 연습 문제 3번의 f() 함수의 함수 정의를 이 형태
 * 로 다시 작성하여라. 현재 사용중인 컴파일러가 이 형태를 처리하는지 확인해 보
 * 아라. 프로그램의 수행 결과는 같은가? (같아야 한다.)
 */

#include <stdio.h>

int z;

void f(x)
int x;
{
    x = 2;
    z += x; 
}


int main(void)
{
    z = 5;
    f(z);   // z = 7
    printf("z = %d\n", z);
    return 0;
}