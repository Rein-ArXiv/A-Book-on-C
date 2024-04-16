/* Chapter 4 exercise 30 */

/* while 문을 goto와 if 문을 사용하여 구현할 수 있음을 보여라. 그리고 어떤 구
 * 문이 더 좋은지 설명하여라.
 */

#include <stdio.h>

int main(void)
{
    int i, n, total = 0;

    printf("while loop\n"); // while loop
    i = 0;
    while (i < 10){
        total += i;
        printf("Total: %d\ti: %d\n", i, total);
        i++;
    }
    putchar('\n');


    printf("goto loop\n"); // goto loop
    i = 0;
    total = 0;

    loop:
        total += i;
        printf("Total: %d\ti: %d\n", i, total);
        i++;

    loop_check:
        if (i < 10){
            goto loop;
        }

    return 0;
}
