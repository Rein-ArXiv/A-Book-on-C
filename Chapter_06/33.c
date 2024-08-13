/* Chapter 6 exercise 33 */

/* 다음 프로그램을 분석하여 분석한 내용을 적어보아라. 이를 위해서는 기억장소 사
 * 상 함수에 대한 이해가 필요하다. 마지막 printf() 문은 더욱 전문적이기 때문
 * 에, 컴퓨터를 전공하는 학생만 설명하여라.
 */

#include <stdio.h>

int main(void)
{
    int a[3][5], i, j, 
        *p = *a;        // a nice initialization

    for (i = 0; i < 3; ++i)
        for (j = 0; j < 5; ++j)
            a[i][j] = i * 5 + j;

    for (i = 0; i < 3; ++i)
        for (j = 0; j < 5; ++j)
        printf("%s%12d", (j == 0) ? "\n" : "", a[i][j]);

    printf("\n");
    for(i = 0; i < 15; ++i)
        printf("%s%12d", (i % 5 == 0) ? "\n" : "", *(p + i));

    printf("\n\n%12d%12d\n%12d%12d\n%12d%12d\n%12d%12d\n\n",
        **a, **(a + 1),
        *(a[0] + 1), *(*a + 1),
        *(a[1] + 2), *(*(a + 1) + 2),
        *(a[2] + 3), *(*(a + 2) + 3));
    
    printf("%-11s%s%12d\n%-11s%s%12d\n%-11s%s%12d\n\n",
        "(int) a", "=", (int) a,
        "(int) *a", "=", (int) *a,
        "(int) **a", "=", (int) **a);
    return 0;
}