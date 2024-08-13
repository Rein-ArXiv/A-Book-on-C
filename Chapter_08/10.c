/* Chapter 8 exercise 10 */

/* ANSI C에서, 표준 헤더 파일은 반복적으로 포함될 수 있고 또한 어떠한 순서로
 * 도 포함될 수 있다. 연습 문제 9번에서 작성한 첫 번째 프로그램의 처음 부분을
 * 다음과 같이 #include가 여러 번 중복되도록 수정해 보아라.

    #include <ctype.h>
    #include <stdio.h>
    #include <time.h>
    #include <ctype.h>
    #include <stdio.h>
    #include <time.h>
    .....                       // repeat a number of times
    int main(void)
    {
        .....


 * 컴파일러는 오류를 발생하는가? 프로그램의 컴파일은 좀 느리게 되더라도, 실행
 * 속도는 같아야 한다. 과연 그러한가?   
 */

#include <ctype.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    int c;

    // Macro, output3. 2 ticks

    printf("Clock ticks: %ld\n", clock());  // start the clock
    while ((c = getchar()) != EOF)
        if (islower(c))
            putchar(toupper(c));
        else if (isupper(c))
            putchar(tolower(c));
        else if (isdigit(c))
            putchar('x');
        else if (ispunct(c)){
            putchar(c);
            putchar(c);    
        }
    putchar('\n');
    printf("Clock ticks: %ld\n", clock());  // ticks up to now
    return 0;
}

