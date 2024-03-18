/* Chapter 2 exercise 11 */

/* 2.12절의 pow_of_2 프로그램에서 ++i 수식을 i++로 바꾸면 어떻게 되겠는가? */

#include <stdio.h>

int main(void)
{
	int i = 0, power = 1;

	while (i++ <= 10)
		printf("%-6d", power *= 2); /* 2048 출력 */
	printf("\n");
	return 0;
}