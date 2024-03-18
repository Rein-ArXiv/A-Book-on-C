/* Chapter 1 exercise 9 */

/* 다음은 화면에 대문자 I를 출력하는 프로그램이다.
   
	#include <stdio.h>

	#define BOTTOM_SPACE	"\n\n\n\n\n"
	#define HEIGHT			17
	#define OFFSET			"                 " // 17 blanks
	#define TOP_SPACE		"\n\n\n\n\n"

	int main(void)
	{
		int i;
		printf(TOP_SPACE);
		printf(OFFSET "IIIIIII\n");
		for (i=0; i<HEIGHT; ++i)
			printf(OFFSET "  III\n");
		printf(OFFSET "IIIIIII\n");
		printf(BOTTOM_SPACE);
		return 0;
	}
 
 * 이 프로그램을 컴파일하고 실행시켜 그 결과를 써라.
 * 그리고 이 프로그램을 분석한 후에 화면에 대문자 C를 출력하는 유사한 프로그램을 작성하여라.
 */

/*






                 IIIIIII
                   III
                   III
                   III
                   III
                   III
                   III
                   III
                   III
                   III
                   III
                   III
                   III
                   III
                   III
                   III
                   III
                   III
                 IIIIIII






*/

#include <stdio.h>

	#define BOTTOM_SPACE	"\n\n\n\n\n"
	#define HEIGHT			17
	#define OFFSET			"                 " /* 17 blanks */
	#define TOP_SPACE		"\n\n\n\n\n"

	int main(void)
	{
		int i;
		printf(TOP_SPACE);
		printf(OFFSET "CCCCCCCCCCCCCCCCCC\n");
		for (i=0; i<HEIGHT; ++i)
			printf(OFFSET "C\n");
		printf(OFFSET "CCCCCCCCCCCCCCCCCC\n");
		printf(BOTTOM_SPACE);
		return 0;
	}


