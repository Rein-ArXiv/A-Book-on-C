/* Chapter 3 exercise 24 */

/* 다음 코드를 포함하는 try_me 프로그램을 작성하여라.

    int c;
    
    while ((c = getchar()) != EOF)
        putchar(c);

 * 그리고 몇 줄의 문장이 들어 있는 infile이라는 파일을 생성하여라. 그런 다음
 * infile의 내용을 outfile로 복사하기 위해 다음 명령어를 수행하고, outfile
 * 파일을 확인해 보아라.

    try_me < infile > outfile

 * 이제 변수 c를 int 형에서 char 형으로 변경한 후 위의 명령을 다시 수행하여
 * 보아라. 어떤 시스템에서는 동작하고, 어떤 시스템에서는 동작하지 않을 것이다.
 * 사용자 시스템은 어떠한가?
 */

#include <stdio.h>

int main(void)
{
    
    int c;
    
    while ((c = getchar()) != EOF)
        putchar(c);

    return 0;
}

