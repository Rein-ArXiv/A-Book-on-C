/* Chapter 2 exercise 15 */

/* 다음 문장에서 괄호를 부분적으로 또는 모두 제거할 경우, 어떤 결과가 초래될 것인지를 설명하여라.

	x = (y = 2) + (z = 3);

 */

#include <stdio.h>

int main(void)
{
	int x, y, z;
	x = (y = 2) + (z = 3);
	printf("x=%d y=%d z=%d\n", x, y, z); /* 5 2 3 */

	x = (y = 2) + z = 3;
	printf("x=%d y=%d z=%d\n", x, y, z); /* error: lvalue required as left operand of assignment */

	x = y = 2 + (z = 3);
	printf("x=%d y=%d z=%d\n", x, y, z); /* 5 5 3 */

	x = y = 2 + z = 3;
	printf("x=%d y=%d z=%d\n", x, y, z); /* error: lvalue required as left operand of assignment */

	return 0;

}