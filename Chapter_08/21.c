/* Chapter 8 exercise 21 */

/* 8.6절 qsort 프로그램은 두 개의 비교 함수를 사용하였다. 이때 qsort() 함수 원
 * 형의 마지막 매개변수와 일치하지 않는 비교 함수를 작성하면 어떻게 되겠는가? 
 * 그 두 비교 함수를 다음과 같이 다시 작성하여라.

    int lexico(char *p, char *q)
    {
        return (*p - *q);
    }

    int compare_decimal_part(float *p, float *q)
    {
        float x;

        x = decimal_part(*p) - decimal(*q);
        return ((x == 0.0) ? 0 : (x < 0.0) ? -1 : +1);
    }
    
 * 또한 main() 함수에 있는 대응되는 함수 원형도 수정하여라. 프로그램이 컴파일
 * 될까? 만일 컴파일된다면, stdlib.h에 있는 qsort()에 대한 함수 원형을 주의
 * 깊게 살펴보아라. 마지막 매개변수가 (compare *)()와 같이 되어 있는가? 만일
 * 이 프로그램이 컴파일되지 않는다면, qsort()의 마지막 인자를 캐스트하여 컴파
 * 일이 되도록 할 수 있는가?
 */


#include "sort.h"

int lexico(char *p, char *q)
{
    return (*p - *q);
}

int compare_decimal_part(float *p, float *q)
{
    float x;

    x = decimal_part(*p) - decimal_part(*q);
    return ((x == 0.0) ? 0 : (x < 0.0) ? -1 : +1);
}

int main(void)
{
    char a[M];
    float b[N];
    int i;

    srand(time(NULL));
    FILL(a, M, "char");
    PRINT(a, M, "%-2c");
    qsort(a, M, sizeof(char), (int (*)(const void *, const void *))lexico);
    PRINT(a, M, "%-2c");
    printf("---\n");
    FILL(b, N, "float");
    PRINT(b, N, "%-6.1f");
    qsort(b, N, sizeof(float), (int (*)(const void *, const void *))compare_decimal_part);
    PRINT(b, N, "%-6.1f");
}