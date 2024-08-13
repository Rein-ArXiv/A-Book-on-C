/* Chapter 1 exercise 10 */

/* 실행이 되는 프로그램을 선택하여 한 행씩 지워가며 컴파일해 보아라.
 * 한 행을 지운 다음 컴파일할 때 발생하는 오류 메시지를 모두 기록하여라.
 * 예를 들어 다음 프로그램을 사용해 보아라.

	#include <stdio.h>

	// forgot main
	{
		printf("nonsense\n");
	}

 */

#include <stdio.h>

/* forgot main */ 			// 1
{							// 2
	printf("nonsense\n");	// 3
}							// 4

/* 1. error: expected identifier or ‘(’ before ‘{’ token */
/* 2. error: expected declaration specifiers or ‘...’ before string constant
	  error: expected identifier or ‘(’ before ‘}’ token */

/* 3. error: expected identifier or ‘(’ before ‘}’ token */

/* 4. in function `_start':
	  (.text+0x1b): undefined reference to `main'
	  collect2: error: ld returned 1 exit status */