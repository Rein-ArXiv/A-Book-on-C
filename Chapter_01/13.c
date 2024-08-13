/* Chapter 1 exercise 13 */

/* for 루프의 형식은 다음과 같다.
 
    for (expr1; expr2; expr3)
        statement

 * 만일 세 수식을 모두 사용한다면, 이 문장은 다음과 같다.

    expr1;
    while (expr2) {
        statement
        expr3;
    }

 * 왜 statement 다음에 세미콜론이 없을까? 물론 statement 자체는 맨 끝에 세미콜론을
 * 포함하는 경우가 대부분이다. 하지만 반드시 그렇지는 않다. C에서 복합문은 중괄호에
 * 둘러싸여 있는 0개 이상의  다른 문장들로 구성되고, 복합문 그 자체도 하나의 문장이다.
 * 따라서 { }와 { ; ; ; }도 문장이다. 다음 코드를 포함하는 프로그램을 작성해 보아라.

    int i;

    for (i=0; i<3; ++i)
        { }                 // no semicolon
    for (i=0; i<3; ++i)
        { ; ; ; }           // three semicolons, but non after the statement

 * 이 프로그램을 컴파일했을 때 문제가 발생하는가? 아마 문제가 없을 것이다. 컴파일러는
 * 구문만을 검사한다. 따라서 코드의 내용이 잘못되어 있다고 해도 구문에만 맞으면
 * 컴파일러는 아무런 오류 메시지도 출력하지 않는다.
 */

#include <stdio.h>

int main(void)
{
    int i;

    for (i=0; i<3; ++i)
        printf("Standard for loop. i=%d\n", i);
    
    for (i=0; i<3; ++i)
        { }

    for (i=0; i<3; ++i)
        { ; ; ; }

    return 0;
}