/* Chapter 8 exercise 12 */

/* 이 연습 문제는 ANSI C와 전통적인 C 사이의 미묘한 차이에 대해 다룬다. 전통
 * 적인 C에서, tolower()와 toupper()는 ctype.h에서 매크로로서 제공된다.
 * ANSI C에서, 그와 대응되는 매크로가 역시 ctype.h에 있지만 각각 _tolower()
 * 와 _toupper()라는 이름으로 되어있다. (이 매크로가 각자의 시스템에서 이용가
 * 능한지 확인해 보아라.) 전통적인 C에서는 c가 소문자라는 것을 이미 알고 있을
 * 때에만 toupper(c)와 같은 수식을 사용할 수 있다. ANSI C에서는 toupper()가
 * 함수로 구현되어 있고, c가 어떤 값을 갖든지 간에 toupper(c) 수식은 유효하다.
 * 만일 c가 소문자가 아니라면, toupper(c)는 아무런 효과가 없다; c를 리턴한다.
 * tolower()도 이와 유사하다. 각자의 시스템에서 직접 실험해 보아라. 다음 수식
 * 은 어떤 출력을 내는지 알아보아라.
 
    tolower('a')    _tolower('a')   toupper('A')    _toupper('A')

 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    printf("%c\t%c\t%c\t%c\n", tolower('a'), _tolower('a'), toupper('A'), _toupper('A'));
    return 0;
}