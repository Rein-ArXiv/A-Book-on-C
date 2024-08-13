/* Chapter 6 exercise 10 */

/* 다음 프로그램에서 change_it() 함수의 호출은 아무런 영향도 없을 것 같다. 이
 * 유를 설명하여라.

    #include <stdio.h>

    void change_it(int []);

    int main(void)
    {
        int a[5], *p;

        p = a;
        printf("p has the value %p\n", p);
        change_it(a);
        p = a;
        printf("p has the value %p\n", p);
        return 0;
    }

    void change_it(int a[])
    {
        int i = 777, *q = &i;

        a = q;          // a is assigned a different value
    }

 */

#include <stdio.h>

void change_it(int []);

int main(void)
{
    int a[5], *p;

    p = a;
    printf("p has the value %p\n", p);
    change_it(a);
    p = a;
    printf("p has the value %p\n", p);
    return 0;
}

void change_it(int a[])
{
    int i = 777, *q = &i;

    a = q;          // a is assigned a different value
}