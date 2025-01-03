#include "mergesort.h"

void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;    // Same as (l+r)/2, but avoids overflow for large l and h

        // Sort first and second halves
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
