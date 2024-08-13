/* Chapter 3 exercise 26 */

/* C에서 16진 상수로는 대문자, 소문자, 또는 둘 다 사용할 수 있다. 다음 코드를
 * 보자.

    int a = 0xabc;
    int b = 0xABc;
    int c = 0XABC;

    printf("a = %d  b = %d  c = %d\n", a, b, c);

 * 어떤 값이 출력되겠는가? 이 코드를 포함하는 프로그램을 작성하여 확인하여 보
 * 아라.
 */

#include <stdio.h>

int main(void)
{
    int a = 0xabc;
    int b = 0xABc;
    int c = 0XABC;

    printf("a = %d  b = %d  c = %d\n", a, b, c);
    return 0;
}

