/* Chapter 2 exercise 7 */

/* ANSI C는 중첩 주석을 허용하지 않지만, 어떤 컴파일러는 이를 허용하기도 한다.
 * 다음 행을 컴파일 했을 때 어떤 일이 일어나는지를 실험해 보아라.

	This is an attempt to nest a comment.

 */

#include <stdio.h>

int main(void)
{
	/* This is an attempt /* to nest */ a comment. */
	return 0;
}

/*

07.c: In function ‘main’:
07.c:14:45: error: unknown type name ‘a’
   14 |         /* This is an attempt /* to nest */ a comment. */
      |                                             ^
07.c:14:54: error: expected ‘=’, ‘,’, ‘;’, ‘asm’ or ‘__attribute__’ before ‘.’ token
   14 |         /* This is an attempt /* to nest */ a comment. */
      |                     
 */
