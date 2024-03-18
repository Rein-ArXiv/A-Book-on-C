/* Chapter 2 exercise 29 */

/* ANSI C에서 각 행의 끝의 \는 이 행을 다음 행으로 계속 연결시켜 주는 효과를 낸다.
 * 이러한 \의 효과는 문자열 상수와 매크로 정의에서 사용할 수 있다. (연습 문제 28번을 참조하여라.)
 * 그러나, 모든 ANSI C 컴파일러가 일반적인 방법으로 이를 제공하는 것은 아니다.
 * 결국, 매크로 정의를 제외하면, 이 방법은 거의 사용되지 않는다. 사용자의 C 컴파일러는
 * 일반적인 방법으로 이것을 제공하는가? 다음 프로그램을 실행하여 보아라.

	#inc\
	lude <stdio.h>

	int mai\
	n(void)
	{
		printf("Will this work?\n");
		ret\
	urn 0;
	}

 */

#inc\
lude <stdio.h>

int mai\
n(void)
{
	printf("Will this work?\n");
	ret\
urn 0;
}
