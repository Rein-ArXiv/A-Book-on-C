/* Chapter 8 exercise 8 */

/* ANSI C에서, 표준 헤더 파일에 있는 인자를 갖는 많은 매크로들은 함수로도 이
 * 용될 수 있어야 한다. 각자의 시스템은 이 함수들을 제공하고 있는가? 예를 들면,
 * 다음과 같은 코드를 처리할 수 있는 지를 알아보아라.

    #include <ctype.h>      // function protype here?

    if ((isalpha)('a'))
        printf("Found the isalpha() function!\n");

 * 이 함수가 제공되지 않는다고 해서 놀랄 필요는 없다. 이들은 자주 사용되는 것이
 * 아니다.
 */

#include <stdio.h>
#include <ctype.h>      // function protype here?

int main(void)
{
    if ((isalpha)('a'))
        printf("Found the isalpha() function!\n");
    return 0;
}