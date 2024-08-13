/* Chapter 2 exercise 22 */

/* 앞의 연습 문제에서는 다음과 같은 코드를 제안하였다.

	seed = time(NULL);
	srand(seed);

 * 대부분의 프로그래머는 다음과 같은 코드를 대신 사용한다.

 	srand(time(NULL));

 * 앞의 프로그램을 이와 같이 수정한 다음, 컴파일하고, 실행시켜 보아라.
 * 이전 프로그램과 똑같이 동작하는가?
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, n;

	srand(time(NULL));
	printf("\n%s\n%s",
		"Some randomly distributed integers will be printed.",
		"How many do you want to see? ");
	scanf("%d", &n);
	
	for (i = 0; i < n; ++i) {
		if (i % 5 == 0)
			putchar('\n');
		printf("%12d", rand());
	}
	printf("\n\n");
	return 0;
}