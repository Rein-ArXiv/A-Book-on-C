/* Chpater 6 exercise 24 */

/* sizeof 연산자는 형이나 수식을 저장하기 위해 필요한 바이트 수를 구하는 데
 * 사용된다. 이 연산자를 배열에 적용하면, 배열의 크기를 내지 않는다. 어떤 값이
 * 출력되는가? 설명하여라.
 */

#include <stdio.h>

void f(int a[]);

int main(void)
{
    char s[] = "deep in the heart of texas";
    char *p = "deep in the heart of texas";
    int a[3];
    double d[5];

    printf("%s%d\n%s%d\n%s%d\n%s%d\n",
        "sizeof(s) = ", sizeof(s),
        "sizeof(p) = ", sizeof(p),
        "sizeof(a) = ", sizeof(a),
        "sizeof(d) = ", sizeof(d));
    f(a);
    return 0;
}

void f(int a[])
{
    printf("In f() : sizeof(a) = %d\n", sizeof(a));
}