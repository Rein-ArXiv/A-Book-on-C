/* Chapter 9 exercise 25 */

/* 다음 코드를 실행하여 각자의 시스템이 int 형의 비트 필드에서 부호 비트를 사
 * 용하는지를 검사해 보아라.

    struct test {
        int a : 3, b : 4;
    } x = {0};

    for ( ; ; )
        printf("x.a = %2d   x.b = %2d\n", x.a++, x.b++)

 */

#include <stdio.h>

struct test {
    int a : 3, b : 4;
} x = {0};

int main(void){
    for ( ; ; )
        printf("x.a = %2d   x.b = %2d\n", x.a++, x.b++);

    return 0;
}