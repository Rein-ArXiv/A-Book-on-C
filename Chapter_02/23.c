/* Chapter 2 exercise 23 */

/* 앞의 두 연습 문제에서는 난수 발생기에 시드를 주기 위해 time()이 리턴하는 값을
 * 사용하였다. 이번 연습 문제에서는 time()의 리턴 값을 사용하여 rand() 함수를
 * 호출하는 데 걸리는 시간을 측정한다. 다음 프로그램은 이를 위한 한 가지 방법을
 * 보여주고 있다.

	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>

	#define NCALLS	10000000	// number of fct calls
	#define NCOLS	8			// number of columns
	#define NLINES	3			// number of lines

	int main(void)
	{
		int i, val;
		long begin, diff, end;

		begin = time(NULL);
		srand(time(NULL));
		printf("TIMING TEST : %d calls to rand()\n", NCALLS);
		for (i = 1; i<= NCALLS; ++i){
			val = rand();
			if (i <= NCOLS * NLINES){
				printf("%12d", val);

				if (i% NCOLS == 0)
					putchar('\n');
			}
			else if (i == NCOLS * NLINES + 1)
				printf("%7s\n\n", "......");
		}
		end = time(NULL);
		diff = end - begin;
		printf("%s%ld\n%s%ld\n%s%ld\n%s%.10f\n\n",
			"end time : ", end,
			"begin time : ", begin,
			"elapsed time : ", diff,
			"time for each call : ", (double) diff / NCALLS);
		return 0;
	}
 
 * 다음은 출력 결과이다.

	TIMING TEST : 10000000 calls to rand()
  	1006497611  321816094  	2046959031  1173375492  291509345  	1938483829  1377840330  954829197
    10349190   	207010746   744437477   387590743  	1900068025 	1733253842  1529587338  2027404216
   	815717934  	1990930106  1694610252  1492413420  651908745  	1627813303  823230032  	2125545885
	......

	end time : 1707189703
	begin time : 1707189702
	elapsed time : 1
	time for each call : 0.0000001000

 * 이 프로그램의 목적은 rand() 호출에 의하여 생성된 값의 일부를 출력하는 것이다.
 * 화면에 천만 개의 숫자를 출력한다는 것은 무의미하다. 프로그램의 #define을 수정하여
 * 어떻게 동작하는지 알아보아라. 예를 들어 다음과 같이 수정하여 수행해 보아라.

	#define NCALLS	10000
	#define NCOLS	7
	#define NLINES	7

 * 주의: 시분할 컴퓨터를 사용할 경우, time()이 리턴하는 값을 사용하면 엉뚱한 결과를
 * 얻을 수 있다. 즉, time() 호출과 time() 호출 사이에 컴퓨터는 다른 작업을 수행
 * 할 수도 있기 때문에, 시간을 측정한 값은 부정확할 수 있다. C 코드의 시간을 정확히
 * 측정하기 위해서는 clock() 함수를 사용해야 한다. (11.16절을 참조하여라.)
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NCALLS	10000000	/* number of fct calls */
#define NCOLS	8			/* number of columns */
#define NLINES	3			/* number of lines */

int main(void)
{
	int i, val;
	long begin, diff, end;

	begin = time(NULL);
	srand(time(NULL));
	printf("TIMING TEST : %d calls to rand()\n", NCALLS);
	for (i = 1; i<= NCALLS; ++i){
		val = rand();
		if (i <= NCOLS * NLINES){
			printf("%12d", val);

			if (i% NCOLS == 0)
				putchar('\n');
		}
		else if (i == NCOLS * NLINES + 1)
			printf("%7s\n\n", "......");
	}
	end = time(NULL);
	diff = end - begin;
	printf("%s%ld\n%s%ld\n%s%ld\n%s%.10f\n\n",
		"end time : ", end,
		"begin time : ", begin,
		"elapsed time : ", diff,
		"time for each call : ", (double) diff / NCALLS);
	return 0;
}