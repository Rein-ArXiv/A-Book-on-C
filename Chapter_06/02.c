/* Chapter 6 exercise 2 */

/* 컴파일러 중 어떤 것은 연습 문제 1번의 수식 p - (p - 2)에 대하여 정수 오버플로
 * 에 관한 경고를 낸다. 연습 문제 1번에서 작성한 프로그램을 수정하여 p와 p - 2 값
 * 을 출력하도록 하여라. 정수 오버플로가 발생하겠는가? (더 자세한 내용은 다음 연
 * 습 문제를 참조하여라.)
 */

#include <stdio.h>

int main(void)
{
    char *format = "%p %d %p %d\n";
    int i = 3;
    int *p = &i;

    printf(format, p, p, p - 2, p - 2);
    return 0;
}