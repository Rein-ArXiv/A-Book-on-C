/* Chapter 5 exercise 20 */

/* 다음 프로그램은 고의적으로 함수의 하단에 외부 변수를 선언한 것이다. 어떤 값
 * 이 출력되는가?
 
    #include <stdio.h>

    int main(void)
    {
        extern int a, b, c;

        printf("%3d%3d%3d\n", a, b, c);
        return 0;
    }
    int a = 1, b = 2, c = 3;

 * 이 프로그램의 마지막 줄을 다음과 같이 수정하여라.

    static int a = 1, b = 2, c = 3;

 * 이제 이 파일의 하단에 있는 변수들은 정적 외부 변수이므로, 이 변수들은
 * main()에서 사용될 수 없다. 그래서, main()에서 참조하는 외부 변수를 찾을 수
 * 없고, 컴파일러는 오류 메시지를 출력할 것이다. 과연 그러한가? (대부분의 컴파일
 * 러가 그럴 것이다.)
 */

#include <stdio.h>

int main(void)
{
    extern int a, b, c;

    printf("%3d%3d%3d\n", a, b, c);
    return 0;
}
// int a = 1, b = 2, c = 3;
static int a = 1, b = 2, c = 3;