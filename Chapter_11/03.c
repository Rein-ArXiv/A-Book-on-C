/* Chapter 11 exercise 3 */

/* getstring()과 putstring() 함수를 작성하여라. 첫 번째 함수는 반드시 ifp와
 * 같은 파일 포인터를 사용해야 하고, ifp가 포인트하는 파일로부터 문자열을 읽기
 * 위해 매크로 getc()를 사용해야 한다. 두 번째 함수는 ofp와 같은 파일 포인터를
 * 사용해야 하고, ofp가 포인트하는 파일에 문자열을 출력할 때는 매크로 putc()
 * 를 사용해야 한다. 그리고 작성한 함수들을 검사할 수 있는 프로그램도 작성하여
 * 라.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000

void getstring(FILE *ifp);
void putstring(FILE *ofp);

int main(int argc)
{

}

void getstring(FILE *ifp)
{
    int c;
    while ((c = getc(ifp)) != EOF)
    {
        
    }
}



void putstring(FILE *ofp)
{
}