/* Chapter 6 exercise 14 */

/* 최대 n차의 두 다항식을 곱하는 알고리즘을 작성하여라. 그리고 중간 결과를 더하
 * 기 위해 연습 문제 13번에서 작성한 add() 함수를 사용하여라. 이 알고리즘은 매
 * 우 비효율적이다. 더 효율적인 루틴을 작성할 수 있는가?
 */

#include <stdio.h>

void add(double f[], double g[], double h[], int n);
void multiplier(double f[], double g[], double h[], int n);

int main(void)
{
    int i, n = 5;
    double f[n], g[n], h[n * 2];

    printf("Polynomial f: ");
    for (i = 0; i < n; i++)
    {
        f[i] = (double) i + 1;      // f = 1, 2, 3, 4, 5
        printf("%.2lf ", f[i]);
    }
    putchar('\n');

    printf("Polynomial g: ");
    for (i = 0; i < n - 1; i++)     // g = 0, 2, 4, 6
    {
        g[i] = (double) 2 * i;
        printf("%.2lf ", g[i]);
    }
    putchar('\n');

    for (i = 0; i < n * 2; i++)
    {
        h[i] = 0;
    }

    multiplier(f, g, h, n);
    
    for (int i = 0; i < n * 2; i++){
        printf("%.2lf ", h[i]);
    }
    putchar('\n');
    
    return 0;
}

void add(double f[], double g[], double h[], int n)
{
    int i;
    
    for (i = 0; i < n; i++)
    {
        h[i] += f[i] + g[i];
    }
}

void multiplier(double f[], double g[], double h[], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            h[i + j] += f[i] * g[j];
        }
    }
}