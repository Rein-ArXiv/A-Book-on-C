/* Chpater 6 exercise 23 */

/* 3장에서 long int에 저장할 수 있는 가장 큰 수는 약 20억임을 보았다. 많은 응
 * 용 프로그램에서, 이 수의 크기는 충분치 않다. 예를 들어, 미연방정부는 수조의
 * 숫자를 다룬다. (또는 천조?) 이 연습 문제에서는 원시적인 방법으로 어떻게 두
 * 개의 커다란 정수를 더할 수 있는지 살펴본다. 프로그램은 다음과 같다.
 
    #include <assert.h>
    #include <stdio.h>

    #define     N   20

    typedef const char cchr;

    void add(int sum[], int a[], int b[]);  // sum = a _ b
    void wrt(cchr *s, int a[]);

    int main(void)
    {
        int a[N] = {7, 5, 9, 8, 9, 7, 5, 0, 0, 9, 9, 0, 8, 8};
        int b[N] = {7, 7, 5, 3, 1, 2, 8, 8, 9, 6, 7, 7};
        int sum[N];

        add(sum, a, b);
        wrt("Integer a: ", a);
        wrt("Integer b: ", b);
        wrt("    Sum: ", sum);
        return 0;
    }

    void add(int sum[], int a[], int b[])
    {
        int carry = 0;
        int i;

        for (i = 0; i < N; ++i){
            sum[i] = a[i] + b[i] + carry;
            if (sum[i] < 10)
                carry = 0;
            else {
                carry = sum[i] / 10;
                sum[i] %= 10;
            }
        }
    }

    void wrt(cchr *s, int a[])
    {
        int i;

        printf("%s", s);

        // Print leading zeros as blanks.

        for (i = N - 1; i >= 0 && a[i] == 0; --i)
            putchar(' ');

        // After a leading digit greater than zero is found,
        // print all the remaining digits, including zeros.

        for (; i >= 0; --i)
            printf("%d", a[i]);
        putchar('\n');
    }

 * 이 프로그램의 수행 결과는 다음과 같다.
 
    Integer a:       88099005798957
    Integer b:         776988213577
          Sum:       88875994012534

 * 숫자는 배열의 원소 0부터 N - 1까지 저장되지만, 출력은 반대로 된다는 것에 주
 * 의하여라. 이 프로그램을 이해하기 위해서는 초등학교에서 더하기를 어떻게 하라
 * 고 배웠는지 생각해 볼 필요가 있다. 2개의 정수의 곱을 계산하는 프로그램을 작
 * 성하여라.
 */

#include <assert.h>
#include <stdio.h>

#define     N   20

typedef const char cchr;

void add(int sum[], int a[], int b[]);  // sum = a + b
void multiply(int mul[], int a[], int b[]);
void wrt(cchr *s, int a[]);
void mul_wrt(cchr *s, int a[]);

int main(void)
{
    int a[N] = {7, 5, 9, 8, 9, 7, 5, 0, 0, 9, 9, 0, 8, 8};
    int b[N] = {7, 7, 5, 3, 1, 2, 8, 8, 9, 6, 7, 7};
    int sum[N];
    int mul[2 * N] = {0};

    add(sum, a, b);
    multiply(mul, a, b);
    wrt("Integer a: ", a);
    wrt("Integer b: ", b);
    wrt("      Sum: ", sum);
    mul_wrt(" Multiply: ", mul);
    return 0;
}

void add(int sum[], int a[], int b[])
{
    int carry = 0;
    int i;

    for (i = 0; i < N; ++i){
        sum[i] = a[i] + b[i] + carry;
        if (sum[i] < 10)
            carry = 0;
        else {
            carry = sum[i] / 10;
            sum[i] %= 10;
        }
    }
}

void multiply(int mul[], int a[], int b[])
{
    int carry = 0;
    int i, j;

    for (i = 0; i < N; ++i){
        for (j = 0; j < N; ++j){
            mul[i + j] += a[i] * b[j] + carry;
            carry = mul[i + j] / 10;
            mul[i + j] %= 10;
        }
        mul[i + j] += carry;
        carry = 0;
    }
}


void wrt(cchr *s, int a[])
{
    int i;

    printf("%s", s);

    // Print leading zeros as blanks.

    for (i = 0; i < 20; i++)
        putchar(' ');

    for (i = N - 1; i >= 0 && a[i] == 0; --i)
        putchar(' ');

    // After a leading digit greater than zero is found,
    // print all the remaining digits, including zeros.

    for (; i >= 0; --i)
        printf("%d", a[i]);
    putchar('\n');
}

void mul_wrt(cchr *s, int a[])
{
    int i;

    printf("%s", s);

    // Print leading zeros as blanks.

    for (i = 2 * N - 1; i >= 0 && a[i] == 0; --i)
        putchar(' ');

    // After a leading digit greater than zero is found,
    // print all the remaining digits, including zeros.

    for (; i >= 0; --i)
        printf("%d", a[i]);
    putchar('\n');
}