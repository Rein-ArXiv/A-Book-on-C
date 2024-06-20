/* Chapter 8 exercise 17 */

/* 연습 문제 16번의 프로그램에서 첫 두 줄을 다음과 같은 세 줄로 대처하여라.

    #include <assert.h>

    #define NDEBUG

    #include <assert.h>
 
 * C 컴파일러는 오류를 발생하는가? C 컴파일러는 오류를 반드시 발생시켜야 되는
 * 가? 힌트: assert.h 헤더 파일에 다음과 같은 것이 있는지 살펴보아라.
 
    #undef assert

 */

#include <assert.h>

#define NDEBUG

#include <assert.h>

int main(void)
{
    int a = 1, b = 2;
    
    assert(a > b);
    return 0;
}