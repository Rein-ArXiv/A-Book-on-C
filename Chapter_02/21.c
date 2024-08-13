/* Chapter 2 exercise 21 */

/* 2.13절의 prn_rand 프로그램을 세 번 실행시켜 각각 100개의 난수를 출력하여라.
 * 각 실행 때마다 동일한 숫자들이 출력되는지 살펴보아라. 많은 응용 프로그램에서
 * 이러한 결과는 바람직한 것이 아니다. 난수 발생기에 시드를 주는 srand()를 사용하도록
 * prn_rand 프로그램을 수정하여라. 프로그램의 첫 부분을 다음과 같이 작성하여라.

	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>

	int main(void)
	{
		int i, n, seed;

		seed = time(NULL);
		srand(seed);
		printf("\n%s\n%s",
			"Some randomly distributed integers will be printed.",
			"How many do you want to see? ");
			......

 * 대부분의 C 시스템에서, time(NULL)은 1970년 1월 1일 이래로 경과된 시간을 초 단위로 리턴한다.
 * (부록 A를 참조하여라.) 이 프로그램에서는 이 값을 변수 seed에 저장하고, 난수 발생기에 시드를
 * 주기 위해 srand(seed)를 호출한다. 이제 연속적으로 호출된 rand()가 리턴하는 값들은
 * [0, RAND_MAX] 구간에 있는 것이지만, 그 순서는 달라진다. 난수 발생기에 제공된 시드 값이
 * 난수의 발생 순서를 결정한다. 만일 time()에 의해 생성된 값을 시드로 사용한다면, 프로그램이 실행될
 * 때마다 시드 값은 다를 것이고, 따라서 발생되는 난수 집합도 달라진다. 이 프로그램을 반복해서
 * 실행해 보아라. 그때마다 다른 숫자 집합이 출력됨을 보게 될 것이다.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, n, seed;

	seed = time(NULL);
	srand(seed);
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