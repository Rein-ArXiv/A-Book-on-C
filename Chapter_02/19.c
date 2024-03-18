/* Chapter 2 exercise 19 */

/* 2.13절의 prn_rand 프로그램을 for 루프 대신 다음과 같은 while 루프를 사용하도록
 * 다시 작성하여라.
	
	while (i++ < n) {
		......
	}

 * 프로그램을 실행하고 그 결과를 이해한 후, i++ < n을 ++i < n으로 바꾼 프로그램을
 * 다시 작성하여라. 이제 프로그램은 다르게 작동할 것이다. while 루프의 몸체를 다시
 * 작성하여 이전 결과와 같은 결과가 나오도록 하여라.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 0, n;

	printf("\n%s\n%s",
		"Some randomly distributed integers will be printed.",
		"How many do you want to see? ");
	scanf("%d", &n);
	
	while (++i <= n) {		/* i++ < n */
		if (i % 8 == 0)
			putchar('\n');
		printf("%7d", rand());
	}
	printf("\n\n");
	return 0;
}