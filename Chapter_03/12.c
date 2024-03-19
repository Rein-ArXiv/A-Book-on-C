/* Chapter 3 exercise 12 */

/* char 형 변수는 작은 정수 값을 저장하는 데 사용될 수 있다. 만일 큰 값이 char
 * 형 변수에 저장되면 어떻게 되는가? 다음 코드를 살펴보자.

    char c1 = 256, c2 = 257;    // too big!

    printf("c1 = %d\nc2 = %d\n", c1, c2);

 * 컴파일할 때 오류 메시지가 출력되지만, 실행은 될 것이다. 어떤 결과가 나올지
 * 생각해 보아라.
 */


#include <stdio.h>

int main(void)
{
    char c1 = 256, c2 = 257;    // too big!

    printf("c1 = %d\nc2 = %d\n", c1, c2);
    return 0;
}