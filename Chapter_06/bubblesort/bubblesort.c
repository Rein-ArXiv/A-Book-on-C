#include "bubblesort.h"

void bubble(int a[], int n)
{
    int i, j, cnt = 0, sorted = 1;

    for (i = 0; i < n - 1; ++i)
    {
        sorted = 1;
        for (j = n - 1; j > i; --j)
        {
            cnt++;
            if (a[j - 1] > a[j]){
                swap(&a[j - 1], &a[j]);
                sorted = 0;
                //printf("Swap %d and %d\n", a[j-1], a[j]);
            }
        }
        
        if (sorted) {
            //printf("All sorted. Check count %d. End.\n", cnt);
            return;
        }
    }
    // printf("Sort end. Count %d. End.\n", cnt);
}