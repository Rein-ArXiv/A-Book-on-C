/* Chapter 4 exercise 9 */

/* 다음 코드를 실행시킬 경우 어떤 값이 출력되는가? 설명해 보아라.

    int i = 7, j = 7;

    if (i == 1)
        if (j == 2)
            printf("%d\n", i = i + j);
    else
        printf("%d\n", i = i - j);
    printf("%d\n", 1);
    
 */

#include <stdio.h>

int main(void)
{
    int i = 7, j = 7;

    if (i == 1)
        if (j == 2)
            printf("%d\n", i = i + j);
    else
        printf("%d\n", i = i - j);
    printf("%d\n", 1);

    return 0;
}