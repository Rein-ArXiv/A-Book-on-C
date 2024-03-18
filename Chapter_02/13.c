/* Chapter 2 exercise 13 */

/* 연습문제 12번에서 작성한 프로그램은 while 루프를 사용한다. while 루프 대신
 * for 루프를 사용하여 같은 일을 수행하는 프로그램을 작성하여라.
 */

#include <stdio.h>

int main(void)
{
	int power;

	for (power=1024; power>0; power/=2)
		printf("%-6d", power);
	printf("\n");
	return 0;
}