/* Chapter 2 exercise 28 */

/* ANSI C와 전통적인 C에서, 문자열 상수의 마지막이 \가 오면, 문자열이 다음 행으로 이어진다는 것을 나타낸다.

	"by using a backslash at the end of the line \
	a string can be extended from one line to the next"
{
 * 이것을 포함하는 프로그램을 작성하여라. 보통 화면의 한 행에는 80개의 문자를 쓸 수 있다.
 * 만일 80자 이상의 문자열을 출력하면 어떤 일이 발생하겠는가?
 */

#include <stdio.h>

int main(void)
{
	printf("by using a backslash at the end of the line \
		a string can be extended from one line to the next");
	return 0;
}