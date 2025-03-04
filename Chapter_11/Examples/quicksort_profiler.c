/* In file main.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50000

void quicksort(int *, int *);

int main(void)
{
    int a[N], i;

    srand(time(NULL));

    for (i = 0; i < N; ++i)
    {
        a[i] = rand() % 1000;
    }

    quicksort(a, a + N - 1);
    
    for (i = 0; i < N - 1; ++i)
    {
        if (a[i] > a[i + 1])
        {
            printf("SORTING ERROR - bye!\n");
            exit(1);
        }
    }
    return 0;
}