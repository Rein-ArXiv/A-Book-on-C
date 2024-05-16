/* Chapter 6 exercise 44 */

/* 컴파일러는 함수 이름 그 자체를 포인터로 취급한다. 이것은 C의 일반적인 규칙
 * 이다. 다음 코드는 옳은가? 컴파일하기 전에 답하여 보아라.

    #include <stdio.h>

    void f(void);
    void g(void);
    void h(void);

    int main(void)
    {
        (*f)();
        return 0;
    }

    void f(void)
    {
        printf("Hello from f().\n");
        (((*g)))();
    }

    void g(void)
    {
        printf("Hello from g().\n");
        (*(*(*h)))();
    }

    void h(void)
    {
        printf("Hello from h().\n");
    }

 */

#include <stdio.h>

void f(void);
void g(void);
void h(void);

int main(void)
{
    (*f)();
    return 0;
}

void f(void)
{
    printf("Hello from f().\n");
    (((*g)))();
}

void g(void)
{
    printf("Hello from g().\n");
    (*(*(*h)))();
}

void h(void)
{
    printf("Hello from h().\n");
}