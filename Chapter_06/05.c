/* Chapter 6 exercise 5 */

/* 변수가 선언되면, 그 변수들이 연속적인 메모리에 위치하는가? 다음과 같은 선언
 * 을 갖는 프로그램을 작성하여라.

    char a, b, c, *p, *q, *r;

 * 그리고 컴파일러에 의해 이 변수들이 배정된 메모리 위치를 출력하여라. 메모리
 * 위치는 순서적인가? 만일 순서적이라면, 증가하는 순서인가 아니면 감소하는 순서
 * 인가? 각 포인터 변수의 주소는 4로 나누어지는가? 만일 그렇다면, 각 포인터 값
 * 은 기계 워드에 저장됨을 의미하는 것일 것이다.
 */

#include <stdio.h>

int main(void)
{
    char a, b, c, *p, *q, *r;
    
    p = &a;
    q = &b;
    r = &c;

    printf("Show in ptr\n");
    printf("p: %p, q: %p, r: %p\n", p, q, r);
    putchar('\n');

    printf("Show in integer\n");
    printf("p: %d, q: %d, r: %d\n", p, q, r);

    return 0;
}
