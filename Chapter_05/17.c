/* Chapter 5 exercise 17 */

/* 다음 함수는 어떤 시스템에서 부정확한 값을 생성할 것이다.

    int factorial(int n)        // wrong
    {
        if (n == 0 || n == 1)
            return 1;
        else
            return (n * factorial(--n));
    }

 * 이 프로그램을 수행해 보고, 함수가 생성하는 값이 왜 시스템 의존적인지 설명해
 * 보아라.
 */

#include <stdio.h>

int factorial(int n);

int main(void)
{
    int n;
    printf("Input number: ");
    scanf("%d", &n);

    printf("%d! = %d\n", n, factorial(n));
    return 0;
}

int factorial(int n)        // wrong
{
    if (n == 0 || n == 1)
        return 1;
    else
        return (n * factorial(--n));    // due to --n, resulting in the form (n -1) * factorial(n-1)
}