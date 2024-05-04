/* Chapter 6 exercise 6 */

/* 다음 프로그램은 %p 형식을 사용하여 어떤 주소들을 출력한다.

    #include <stdio.h>

    int main(void)
    {
        int a = 1, b = 2, c = 3;

        printf("%s%p\n%s%p\n%s%p\n",
                "&a = ", &a,
                "&b = ", &b,
                "&c = ", &c);
        return 0;
    }

 * 변수 a, b, c가 최적화되지 않았다면, 프로그램은 동일한 결과를 출력하겠는가?
 * %p를 %d로 수정하면, 어떻게 되겠는가? 컴파일러는 오류 메시지를 출력하겠는가?
 * (그럴 것이다.) 가능하다면, 프로그램을 MS-DOS 시스템에서 실행해 보아라. 포
 * 인터는 4 바이트이고 int는 2 바이트이기 때문에, %d 형식은 적절하지 않을 것이
 * 고, 음수 값이 출력되는 원인일 수 있다.
 */

#include <stdio.h>

int main(void)
{
    int a = 1, b = 2, c = 3;

    printf("%s%p\n%s%p\n%s%p\n",
            "&a = ", &a,
            "&b = ", &b,
            "&c = ", &c);
    return 0;
}

