/* Chapter 5 exercise 10 */

/* 5.4절의 tbl_of_power 프로그램에서 main() 함수 정의를 먼저 작성했다. 함수
 * 원형을 다 지우고 main() 함수를 맨 뒤에 작성하면 어떤 일이 발생하는가? 컴파
 * 일러는 별 문제없이 수행될 것이다. 그러한가? 함수 원형을 다 지운 상태에서
 * main() 함수를 맨 앞으로 옮기면 어떻게 되겠는가? 컴파일러가 어떤 메시지를
 * 출력할지 생각해 보아라. 어떤 C 컴파일러는 경고 메시지를 출력하지만, 실행 파
 * 일은 만든다. 반면에, C++ 컴파일러는 오류 메시지를 출력하고, 더 이상 컴파일하
 * 지 않는다. 사용자 시스템에서는 어떻게 되는가?
 */

#include <stdio.h>

#define     N   7

void prn_heading(void)
{
    printf("\n::::: A TABLE OF POWERS :::::\n\n");
}

long power(int m, int n)
{
    int i;
    long product = 1;

    for (i = 1; i <= n; ++i)
        product *= m;
    return product;
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
    putchar('\n');
}

int main(void)
{
    prn_heading();
    prn_tbl_of_powers(N);
    return 0;
}