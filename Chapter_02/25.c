/* Chapter 2 exercise 25 */

/* 이 연습 문제는 연습 문제 21번에 이어지는 것이다. rand()를 호출하면,
 * [0, RAND_MAX] 구간의 값을 생성하고, RAND_MAX는 일반적으로 32767
 * 값을 가진다. 이 값은 그렇게 큰 값이 아니기 때문에, 많은 과학 문제에 있어서
 * 적합하지 않다. UNIX 컴퓨터 상의 대부분의 C 시스템은 rand48 계열의 함수
 * 발생기를 제공한다. rand48은 숫자를 생성하는데 48비트 계산을 이용함으로써
 * 붙여진 이름이다. 예를 들어, drand48() 함수는 [0, 1] 범위 내에 무작위로
 * 분산된 double 값을 생성하기 위해 사용될 수 있다. 연습 문제 21번의 프로그램에서
 * rand()를 lrand48()로 대치하고, srand()를 srand48()로 대치하여 프로그램을
 * 다시 작성하여라. 그러면 평균적으로 더 큰 숫자가 생성되는 것을 볼 수 있을
 * 것이다. 응용 프로그램에 따라 큰 숫자를 생성하는 것이 더 좋을 수 있다. 의사난수
 * 발생기에 관하여 더 자세한 것을 알고자 하면 William Press 등이 집필한
 * "Numerical Recipes in C"의 274~328 쪽을 참고하여라.
 * (Cambridge, England:Cambridge University Press, 1992) 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, n, seed;

	seed = time(NULL);
	srand48(seed);
	printf("\n%s\n%s",
		"Some randomly distributed integers will be printed.",
		"How many do you want to see? ");
	scanf("%d", &n);
	
	for (i = 0; i < n; ++i) {
		if (i % 5 == 0)
			putchar('\n');
		printf("%12ld", lrand48());
	}
	printf("\n\n");
	return 0;
}