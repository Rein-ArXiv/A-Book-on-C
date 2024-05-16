/* Chapter 6 exercise 42 */

/* 다음 프로그램을 컴파일하고 실행하여 프로그램을 이해하여라.

    #include <stdio.h>
    #include <string.h>

    void tell_me(int f(const char *, const char *));

    int main(void)
    {
        tell_me(strcmp);
        tell_me(main);
        return 0;
    }

    void tell_me(int f(const char *, const char *))
    {
        if (f == strcmp)
            printf("Address of strcmp() : %p\n", f);
        else
            printf("Function address : %p\n", f);
    }
 
 * tell_me() 함수에 대한 두 번째 호출에서, 전달되는 포인터가 잘못된 형을 가지
 * 고 있기 때문에 컴파일러는 경고 메시지를 발생시킬 것이다. 그러한가? 경고 메시
 * 지가 나타나지 않도록 void * 포인터형을 사용하는 프로그램으로 수정하여라.
 */

#include <stdio.h>
#include <string.h>

void tell_me(void * f);

int main(void)
{
    tell_me((void *) strcmp);
    tell_me((void *) main);
    return 0;
}

void tell_me(void * f)
{
    if (f == (void *)strcmp)
        printf("Address of strcmp() : %p\n", f);
    else
        printf("Function address : %p\n", f);
}