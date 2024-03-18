/* Chapter 2 exercise 12 */

/* 다음 코드는 pow_of_2 프로그램에 사용할 수 있는 다른 방법이다. 출력될 결과를 쓰고,
 * 프로그램을 완성하여 수행한 후 답을 비교해 보아라.

 	int power = 2048;
 	while ((power /=2) > 0)
 		printf("%-6d", power);
 */

#include <stdio.h>

int main(void)
{
	int power = 2048;

	while ((power /= 2) > 0)
		printf("%-6d", power); /* 1024	512	 256  128  64  32  16  8  4  2  1 */
	printf("\n");
	return 0;
}