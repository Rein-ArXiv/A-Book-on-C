/* Chpater 6 exercise 28 */

/* ANSIC 위원회는 C 언어에 새로운 예약어인 형 한정자 const를 추가하였다. 다
 * 음 예제를 보자.

    const char *p;

 * 형 한정자 const는 컴파일러에게 p가 포인트하는 문자는 변경될 수 없음을 알려
 * 준다. ("p는 상수 char에 대한 포인터이다"라고 읽는다.) 이것의 적용은 컴파일러
 * 마다 다르다. 다음 코드를 수행해 보아라.

    char s[] = "abc";
    const char *p = s;

    *p = 'A';       // illegal?
    printf("%s\n", s);

 * 컴파일러가 오류 메시지를 내는가? (그럴 것이다.)
 */

#include <stdio.h>

int main(void)
{
    char s[] = "abc";
    const char *p = s;

    *p = 'A';       // illegal?
    printf("%s\n", s);
    return 0;
}