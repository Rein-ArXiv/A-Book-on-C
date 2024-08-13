/* Chpater 6 exercise 18 */

/* 6.11절에서 제시한 strcpy()를 위한 함수 정의를 잘 살펴보고, 문자열의 끝 부분
 * 을 문자열의 앞에 복사하는 것이 가능한지 생각해 보아라. 다음 코드의 출력 결과
 * 는 무엇이겠는가? 설명해 보아라.
 
    char a[] = "abcdefghijklmnopqrstuvwxyz";
    char *p = a;
    char *q = a + strlen(a) - 3;

    printf("a = %s\n", a);
    strcpy(p, q);
    printf("a = %s\n", a);

    return 0;

 * strcpy()를 호출할 때 p와 q를 바꾸어 쓴다면 어떻게 잘못되는지 설명해 보아라.
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[] = "abcdefghijklmnopqrstuvwxyz";
    char *p = a;
    char *q = a + strlen(a) - 3;

    printf("a = %s\n", a);
    strcpy(p, q);
    printf("a = %s\n", a);

    return 0;
}