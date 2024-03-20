/* Chapter 3 exercise 23 */

/* 전통적인 C에서, long float 형과 double 형은 동의어이다. 그러나, long
 * float은 타이핑하기 어려워서 일반화되지 못하였고, 자주 사용되지도 않았다.
 * ANSI C에서는 long float 형이 제거되었다. 그럼에도 불구하고 많은 ANSI C
 * 컴파일러에서 여전히 long float 형을 사용할 수 있다. 사용자의 컴파일러에서도
 * 이것이 사용 가능한지를 조사해 보아라.
 */

#include <stdio.h>

int main(void)
{
    long float x = 1.0;

    printf("size of long float = %lu\n", sizeof(x));
    return 0;
}

