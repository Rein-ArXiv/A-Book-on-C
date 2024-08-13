/* Chapter 9 exercise 26 */

/* 다음 코드를 수행시키면 어떤 출력 값을 얻을 것인지 쓰고, 설명하여라.

    typedef struct a { unsigned a : 1, : 0, b : 1; } a;
    typedef struct b { unsigned a : 1, b : 1; } b;
    printf("%.1f\n", (float) sizeof(a) / sizeof(b));

 */

#include <stdio.h>

int main(void)
{
    typedef struct a { unsigned a : 1, : 0, b : 1; } a;     // 0 bit field padding
    typedef struct b { unsigned a : 1, b : 1; } b;
    printf("%.1f\n", (float) sizeof(a) / sizeof(b));
    return 0;
}

