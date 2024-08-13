/* Chapter 8 exercise 2 */

/* 다음과 같은 매크로 정의를 생각해 보자.

    #define forever(x) forever(forever(x))
    forever(more)

 * 이 코드는 무한적인 재귀를 생성할 것처럼 보이지만, ANSI C의 전처리기는 무한
 * 재귀를 의도한 것이 아님을 알 수 있을 만큼 지능적이다. 이 매크로가 어떻게 확
 * 장되는지 확인해 보아라.
 */

#include <stdio.h>

#define forever(x) forever(forever(x))

int main(void){
    int more = 1;
    forever(more);

    return 0;
}

/*

02.c:19:5: error: call to undeclared function 'forever'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
   19 |     forever(more);
      |     ^
02.c:15:20: note: expanded from macro 'forever'
   15 | #define forever(x) forever(forever(x))
      |                    ^
1 error generated.

*/
