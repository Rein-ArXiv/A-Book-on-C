/* Chapter 2 exercise 20 */

/* rand() 함수에 의해 생성되는 정수들은 모두 [0, n] 구간 내에 들어간다. 여기서
 * n은 시스템 종속적이다. ANSI C의 n 값은 표준 헤더 파일 stdlib.h에 정의된
 * 기호 상수 RAND_MAX에 의해 주어진다. 사용자의 시스템에서 사용된 RAND_MAX의
 * 값을 출력하는 프로그램을 작성하여라. 힌트: stdlib.h 헤더 파일을 포함시키고
 * 다음 문장을 사용하여라.

	printf("RAND_MAX = %d\n", RAND_MAX);

 * 가능하다면, 작성한 프로그램을 다른 C 시스템에서도 실행시켜 보아라. 아마
 * RAND_MAX는 모든 시스템에서 같은 값을 갖는다는 것을 알 수 있을 것이다. 이것은
 * ANSI C 위원회가 rand() 함수를 어떻게 구현해야 한다고 제시하였고, 컴파일러를
 * 만드는 대부분의 작성자가 이 제안을 받아들였기 때문이다. 실험해본 결과 다양한
 * PC, UNIX 워크스테이션, Cray 슈퍼컴퓨터에서 RAND_MAX의 값은 같았고,
 * 그 출력값도 같았다. (연습 문제 25번을 참조하여라.)
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("RAND_MAX = %d\n", RAND_MAX); /* 2147483647 */
	return 0;
}