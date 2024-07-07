/* Chapter 9 exercise 19 */

/* 다음과 같은 union 선언을 보자.

    union a{
        int a;
        char b;
        float a;
    } a, b, c;
 
 * 이 선언에서 한가지 잘못된 부분이 있다. 어떤 것인가?
 */

#include <stdio.h>

union a{
    int a;
    char b;
    float c;    // float a to c
} a, b, c;

int main(void)
{
    a.a = 4;
    b.b = 'a';
    c.c = 0.5f;

    printf("%d %c %f\n", a, b, c);
    return 0;
}