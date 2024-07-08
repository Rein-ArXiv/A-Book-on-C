/* Chapter 9 exercise 24 */

/* 다음 프로그램을 실행시키면 어떤 값이 출력되는지를 쓰고, 설명하여라.

    #include <stdio.h>

    struct test {
        unsigned a : 1, b : 2, c : 3;
    };

    int main(void)
    {
        int i;
        struct test x;

        for (i = 0; i < 23; ++i) {
            x.a = x.b = x.c = i;
            printf("x.a = %d    x.b = %d    x.c = %d\n",
                    x.a, x.b, x.c);
        }
        return 0;
    }

 * 만일 x.a = x.b = x.c = i;를 x.c = x.b = x.a = i;로 대치하면 수행결과가
 * 어떻게 되겠는가?
 */

#include <stdio.h>

struct test {
    unsigned a : 1, b : 2, c : 3;
};

int main(void)
{
    int i;
    struct test x;

    for (i = 0; i < 23; ++i) {
        x.a = x.b = x.c = i;
        printf("x.a = %d    x.b = %d    x.c = %d\n",
                x.a, x.b, x.c);
    }

    putchar('\n');

    for (i = 0; i < 23; ++i) {
        x.c = x.b = x.a = i;
        printf("x.a = %d    x.b = %d    x.c = %d\n",
                x.a, x.b, x.c);
    }
    return 0;
}