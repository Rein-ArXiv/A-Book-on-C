/* Chapter 6 exercise 43 */

/* 다음 프로그램은 오류를 포함하고 있다.

    #include <stdio.h>
    #include <string.h>

    int main(void)
    {
        char *p1 = "abc", *p2 = "pacific sea";

        printf("%s  %s  %s\n", p1, p2, strcat(p1, p2));
        return 0;
    }

 * 그 결과는 컴파일러에 따라 달라진다. 어떤 컴파일러를 사용하면, 이 프로그램은
 * 실행 시간 오류를 발생시킨다. 그리고, 다른 컴파일러를 사용하면, 다음과 같은 결
 * 과가 화면에 출력된다.
 
    abcpacific sea  acific sea  abcpacific sea

 * 이러한 결과는 의미가 있으며, 컴파일러에 대한 무엇인가를 알려준다. 프로그래밍
 * 오류는 무엇인가? 이 결과를 통하여 컴파일러에 대해 어떤 것을 알 수 있는가?
 * 실행 시간 오류를 발생시키는 실행 코드를 만드는 컴파일러와 논리적으로 잘못된
 * 결과를 생성하는 컴파일러 중 어느 것이 더 바람직하겠는가?
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char *p1 = "abc", *p2 = "pacific sea";

    printf("%s  %s  %s\n", p1, p2, strcat(p1, p2));
    return 0;
}