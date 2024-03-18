/* Chapter 1 exercise 5 */

/* 다음 프로그램은 실행시간 오류를 유발할 것이다.
   
   #include <stdio.h>
   
   int main(void)
   {
      int x, y = 0;

      x = 1 / y;
      printf("x=%d\n", x);
      return 0;
   }
  
 * 이 프로그램을 컴파일해 보아라. 아마 아무런 오류 메시지도 발생하지 않을 것이다.
 * 이 프로그램을 실행시켜 보면, 영으로 정수를 나누는 것이 어떤 결과를 가져오는 지를
 * 알 수 있을 것이다. 대부분의 시스템에서 이 프로그램은 실행시간 오류를 발생시킨다.
 * 만일 여러분의 시스템 상에서 실행시간 오류가 발생했다면, 이 프로그램에서 변수 y를
 * 사용하지 말고 직접 영을 사용하여 나누기를 해 보아라. 이제 어떤 일이 일어나는가?
 */

#include <stdio.h>

int main(void)
{
   int x, y = 0;

   x = 1 / y; /* if use 0, there is warning in compile. "warning: division by zero [-Wdiv-by-zero]" */
   printf("x=%d\n", x); /* use 'y' : x=0, use 0 : NULL*/
   return 0;
}