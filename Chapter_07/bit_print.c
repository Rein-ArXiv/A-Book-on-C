#include <stdio.h>
#include <limits.h>

void bit_print(int a)
{
    int i;
    int n = sizeof(int) * CHAR_BIT;
    int mask = 1 << (n - 1);

    for (i = 1; i <= n; ++i){
        putchar(((a & mask) == 0) ? '0' : '1');
        a <<= 1;

        if (i % CHAR_BIT == 0 && i < n)
            putchar(' ');
    }
}

int main(void)
{
    int a = 1;

    bit_print(a);
    return 0;
}