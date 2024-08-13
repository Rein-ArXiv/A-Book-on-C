/* Chpater 6 exercise 27 */

/* 다음 코드를 보자.

    char *p = "abc", *q = "abc";

    if (p == q)
        printf("The two string have the same address!\n");
    else
        printf("As I expected, the addresses are different.\n");

 * p와 q는 문자열 상수 "abc"의 기본 메모리 주소로 초기화되었다. p == q는 p와
 * q의 값이 같은지 검사하는 것이다. 즉, p와 q가 포인트하고 있는 곳의 내용을 검
 * 사하는 것은 아니다. 메모리에 이 두 문자열 상수가 따로 있겠는가, 아니면 하나
 * 로 있겠는가? 이것은 컴파일러에 따라 다르다. 또한 많은 컴파일러들은 옵션을 두
 * 어, 같은 내용의 문자열 상수들을 따로 저장할지, 아니면 한 문자열만 저장할 지
 * 를 선택할 수 있게 한다. 전통적인 C에서는 문자열 상수들이 변경될 수 있기 때
 * 문에, 같은 내용의 문자열 상수들이 따로 저장된다. (연습 문제 26번을 참조하여
 * 라.) 이와는 반대로, 많은 ANSI C의 컴파일러들은 같은 장소에 이들을 저장한다.
 * 각자의 시스템에서는 어떻게 되는가?
 */

#include <stdio.h>

int main(void)
{
    char *p = "abc", *q = "abc";

    if (p == q)
        printf("The two string have the same address!\n");
    else
        printf("As I expected, the addresses are different.\n");
    
    return 0;
}