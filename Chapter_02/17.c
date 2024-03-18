/* Chapter 2 exercise 17 */

/* 다음 코드를 보자.

	int a = 1, b = 2, c = 3;

	a += b += c += 7;

 * 이 문장을 완전한 괄호로 표현된 동일한 문장으로 기술해 보아라. a, b, c 변수의 값은
 * 어떻게 되겠는가? 생각하는 답을 먼저 적고, 프로그램을 작성하여 확인해 보아라.
 */

#include <stdio.h>

int main(void)
{
	int a = 1, b = 2, c = 3;

	a += (b += (c += 7));

	printf("a=%d, b=%d, c=%d\n", a, b, c); /* a = 13, b = 12, c = 10 */
	return 0;
}