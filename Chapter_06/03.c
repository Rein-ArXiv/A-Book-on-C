/* Chapter 6 exercise 3 */

/* 다음 프로그램을 보자.

    #include <stdio.h>
    #include <stddef.h>

    int main(void)
    {
        int a, b, *p = &a, *q = &b;

        ptrdiff_t diff = p - q;
        printf("diff = %d\n", diff);
        return 0;
    }

 * ANSI C에서, 두 포인터 수식의 차는 부호 있는 정수적형이어야 한다. 대부분의
 * UNIX 시스템에서 그 형은 int이고, 대부분의 MS-DOS 시스템에서 그 형은
 * long이다. 모든 ANSI C 시스템에서, 그 형은 표준 헤더 파일 stddef.h에 다음
 * 과 같은 형 선언으로 주어진다.
 
    typedef type ptrdiff_t;

 * 현재 사용하고 있는 시스템의 stddef.h에서 이 typedef를 찾아보면, diff의 형
 * 을 알게 될 것이다. diff가 int 형이면 printf() 문에서 %d가 적절할 것이고,
 * long 형이면 %ld가 적절할 것이다. 이 프로그램을 수행한 후 그 효과를 이해하여
 * 라. 그 후 프로그램에 다음과 같은 두 행을 추가하여라.
 
    diff = p - (int *) 0;
    printf("diff = %d\n", diff);

 * 기대했던 출력 값이 나왔는가? 이것을 통해 연습 문제 2번에서 논의한 컴파일러
 * 의 경고가 발생한 이유를 이해하겠는가? 설명하여라. 만일 int *를 ptrdiff_t *
 * 로 대치한다면, 프로그램은 다르게 동작하겠는가?
 */

#include <stdio.h>
#include <stddef.h>

int main(void)
{
    int a, b, *p = &a, *q = &b;

    ptrdiff_t diff = p - q;
    printf("diff = %d\n", diff);
    
    diff = p - (int *) 0;
    printf("diff = %d\n", diff);

    diff = p - (ptrdiff_t *) 0;
    printf("diff = %d\n", diff);
    return 0;
}
