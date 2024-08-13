/* Chapter 6 exercise 13 */

/* 최대 n차의 두 다항식을 더하는 함수를 작성하여라.

    // f = g + h;   n is the max degree of f, g, and h

    void add(double f[], double g[], double h[], int n)
    {
        .....

 */

#include <stdio.h>

void add(double f[], double g[], double h[], int n);

int main(void)
{
    int n = 5;
    double f[5] = {1.0, 2.0, 3.0};
    double g[5] = {2.0, 4.0, 6.0, 8.0, 10.0};
    double h[5] = {0};

    add(f, g, h, n);
    
    for (int i = 0; i < n; i++){
        printf("%lf ", h[i]);
    }
    putchar('\n');
    
    return 0;
}

void add(double f[], double g[], double h[], int n)
{
    int i;
    
    for (i = 0; i < n; i++)
    {
        h[i] = f[i] + g[i];
    }
}