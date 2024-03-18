/* Chapter 2 exercise 24 */

/* rand() 함수는 [0, RAND_MAX] 구간의 값을 리턴한다. (연습 문제 20번을 참조하여라.)
 * double 형의 변수 median을 선언하고 초기 값을 RAND_MAX / 2.0으로 하여라. 연속해서
 * rand()를 호출하면, 어떨 때에는 median보다 큰 값을 리턴하고, 어떨 때에는 작은 값을
 * 리턴할 것이다. 평균적으로 median보다 클 경우와 적을 경우의 확률은 같을 것이다.
 * 이 가설을 시험해 보아라. for 루프를 사용하여 rand()를 500번 호출하고, rand()의
 * 리턴 값이 median보다 크면 above_cnt 변수를 증가시키고, 작으면 below_cnt를
 * 증가시키는 프로그램을 작성하여라. 그리고 for 루프를 수행할 때마다 above_cnt와
 * below_cnt 값의 차를 출력하여라. 그 값은 0 주위에서 진동해야 한다. 그러한가?
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	double median = RAND_MAX / 2.0;
	int above_cnt = 0, below_cnt = 0, random_num;

	printf("median: %lf\n", median);

	for (int i=0; i<500; i++){
		random_num = rand();
		if (random_num > median){
			above_cnt++;
		}
		else if (random_num < median){
			below_cnt++;
		}
		printf("above_cnt - below_cnt = %d\n", above_cnt - below_cnt); /* above_cnt > below_cnt */
	}
	return 0;
}