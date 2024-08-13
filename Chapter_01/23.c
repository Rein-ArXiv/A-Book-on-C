/* Chapter 1 exercise 23 */

/* 1.8절의 abc 프로그램에서 다음 루프를 사용하였다.
 
    for ( ; *p != '\0'; ++p) {
        if (*p == 'e')
            *p = 'E';
        if (*p == ' ')
            *p = '\n';
    }

 * 이 for 루프는 두 개의 if 문으로 구성되기 때문에 중괄호를 사용하였다.
 * 이 코드를 다음과 같이 수정하여라.

    for ( ; *p != '\0'; ++p)
        if (*p == 'e')
            *p = 'E';
        else if (*p == ' ')
            *p = '\n';

 * 수정된 코드는 왜 중괄호가 필요 없는지 설명하여라. 이렇게 수정한 프로그램의
 * 결과도 이전 프로그램의 결과와 같은지 살펴보아라. 같다면 그 이유를 설명하여라.
 */

#include <stdio.h>
#include <string.h>

#define MAXSTRING 100

int main(void)
{
   char   c = 'a', *p, s[MAXSTRING];

   p = &c;
   printf("%c%c%c  ", *p, *p + 1, *p + 2);
   strcpy(s, "ABC");
   printf("%s  %c%c%s\n", s, *s + 6, *s + 7, s + 1);
   strcpy(s, "she sells sea shells by the seashore");
   p = s + 14;
   for ( ; *p != '\0'; ++p)
      if (*p == 'e')
         *p = 'E';
      else if (*p == ' ')
         *p = '\n';
         
   printf("%s\n", s);
   return 0;
}
