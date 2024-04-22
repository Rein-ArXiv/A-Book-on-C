/* Chapter 5 exercise 9 */

/* 5.4절의 tbl_of_powers 프로그램을 실행시켜 보아라. 부정확한 값이 출력되기까지
 * 몇 개의 행이 계산되는가? double 형으로 수정하여 다시 수행해 보아라. 그 행의
 * 개수가 더 커지는가?
 */

#include <stdio.h>

#define     N   7

long power(int, int);

void prn_heading(void);
void prn_tbl_of_powers(int);

int main(void)
{
    prn_heading();
    prn_tbl_of_powers(N);
    return 0;
}

void prn_heading(void)
{
    printf("\n::::: A TABLE OF POWERS :::::\n\n");
}

void prn_tbl_of_powers(int n)
{
    int i, j;

    for(i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j)
            if (j == 1)
                printf("%ld", power(i, j));
            else
                printf("%9ld", power(i, j));
        putchar('\n');
    }
}

long power(int m, int n)
{
    int i;
    long product = 1;

    for (i = 1; i <= n; ++i)
        product *= m;
    return product;
}