/* Chapter 8 exercise 15 */

/* 다음 지시자를 보자.

    #undef  TRY_ME

 * TRY_ME가 이전에 #define 매크로로 정의되었다면, 이 지시자 때문에 그 매크로
 * 정의는 무효가 된다. TRY_ME가 이전에 정의되지 않았다면, 이 지시자는 아무런
 * 영향도 미치지 않을 것이다. 각자의 시스템에서는 어떤 일이 발생하는지를 검사하
 * 는 프로그램을 작성하여라. TRY_ME가 이전에 정의되어 있지 않다면, 시스템은 오
 * 류를 발생하는가?
 */

#include <stdio.h>

#undef  TRY_ME

int main(void)
{
    printf("Works Well.\n");
    return 0;
}