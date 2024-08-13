/* Chapter 2 exercise 14 */

/* 다음 코드를 보고, 출력될 값들을 적어 보아라. 그 다음 프로그램을 작성하여
 * 수행한 후 답을 비교해 보아라.

	int a, b = 0, c = 0;

	a = ++b + ++c;
	printf("%d %d %d \n", a, b, c);
	a = b++ + c++;
	printf("%d %d %d\n", a, b, c);
	a = ++b + c++;
	printf("%d %d %d\n", a, b, c);
	a = b-- + --c;
	printf("%d %d %d\n", a, b, c);

 *
 */

#include <stdio.h>

int main(void)
{
	int a, b = 0, c = 0;

	a = ++b + ++c;
	printf("%d %d %d \n", a, b, c);	/* 2 1 1 */
	a = b++ + c++;
	printf("%d %d %d\n", a, b, c); 	/* 2 2 2 */
	a = ++b + c++;
	printf("%d %d %d\n", a, b, c);	/* 5 3 3 */
	a = b-- + --c;
	printf("%d %d %d\n", a, b, c);	/* 5 2 2 */

	return 0;
}