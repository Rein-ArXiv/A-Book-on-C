/* Chapter 4 exercise 11 */

/* 다음 코드는 무한 루프에 빠질 수 있는가? 설명하여라. (i와 j 값은 루프 몸체에
 * 서 변경되지 않는다고 가정한다.)

    printf("Input two integers : ");
    scanf("%d%d", &i, &j);
    while (i * j < 0 && ++i != 7 && j++ != 9){
        .....   // do something
    }

 */

#include <stdio.h>

int main(void)
{
    int i, j;
    printf("Input two integers : ");
    scanf("%d%d", &i, &j);
    while (i * j < 0 && ++i != 7 && j++ != 9){
        printf("i: %d, j: %d\n", i, j);
    }
    return 0;
}