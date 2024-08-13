/* Quicksort! Pointer version with macros. */

#include <stdio.h>
#include <stdlib.h>

#define swap(x, y)  { int t = x; x = y; y = t; }
#define order(x, y) if (x > y) swap(x, y)
#define o2(x, y)    order(x, y)
#define o3(x, y, z) o2(x, y); o2(x, z); o2(y, z)
#define o5(a, b, c, d, e) o2(a, b); o2(a, c); o2(a, d); o2(a, e); \
                          o2(b, c); o2(b, d); o2(b, e); \
                          o2(c, d); o2(c, e); \
                          o2(d, e)

typedef enum {yes, no} yes_no;

static yes_no find_pivot(int *left, int *right, int *pivot_ptr);
static int *partition(int *left, int *right, int pivot);

int cnt = 0;

void quicksort(int *left, int *right)
{
    if (left >= right) return; // Check for base case

    int *p, pivot;

    if (find_pivot(left, right, &pivot) == yes) {
        p = partition(left, right, pivot);
        quicksort(left, p - 1);
        quicksort(p, right);
    }
    ++cnt;
}

static yes_no find_pivot(int *left, int *right, int *pivot_ptr)
{
    int a, b, c, d, e, *p;
    int size = right - left + 1;

    if (size < 5) {
        a = *left;                          // left value
        b = *(left + size / 2);             // middle value
        c = *right;                         // right value
        o3(a, b, c);

        if (a < b) {    
            *pivot_ptr = b;
            return yes;
        }
        if (b < c) {
            *pivot_ptr = c;
            return yes;
        }
    } else {
        a = *left;                          // left value
        b = *(left + size / 4);             // quarter value
        c = *(left + size / 2);             // middle value
        d = *(left + 3 * size / 4);         // three quarter value
        e = *right;                         // right value
        o5(a, b, c, d, e);

        if (a < c) {
            *pivot_ptr = c;
            return yes;
        }
    }

    for (p = left + 1; p <= right; ++p) {
        if (*p != *left) {
            *pivot_ptr = (*p < *left) ? *left : *p;
            return yes;
        }
    }
    return no; // all elements have the same value
}

static int *partition(int *left, int *right, int pivot)
{
    while (left <= right) {
        while (*left < pivot)
            ++left;
        while (*right >= pivot)
            --right;
        if (left < right) {
            swap(*left, *right);
            ++left;
            --right;
        }
    }
    return left;
}
