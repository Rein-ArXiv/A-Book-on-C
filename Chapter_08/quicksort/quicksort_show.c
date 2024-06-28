#include <stdio.h>

#define swap(x, y)  { int t; t = x; x = y; y = t; }
#define order(x, y) if (x > y) swap(x, y)
#define o2(x, y)    order(x, y)
#define o3(x, y, z) o2(x, y); o2(x, z); o2(y, z)

typedef enum {yes, no} yes_no;

static yes_no find_pivot(int *left, int *right, int *pivot_ptr);
static int *partition(int *left, int *right, int pivot);
static void print_array(const int *a, int size, const int *left, const int *right);

int cnt = 0; 

void quicksort(int *left, int *right)
{
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
    int a, b, c, *p;

    a = *left;                          // left value
    b = *(left + (right - left) / 2);   // middle value
    c = *right;                         // right value
    o3(a, b, c);

    if (a < b) {    // pivot will be higher of 2 values
        *pivot_ptr = b;
        return yes;
    }
    if (b < c) {
        *pivot_ptr = c;
        return yes;
    }

    for (p = left + 1; p <= right; ++p)
        if (*p != *left) {
            *pivot_ptr = (*p < *left) ? *left : *p;
            return yes;
        }
    return no;      // all elements have the same value
}

static void print_array(const int *a, int size, const int *left, const int *right)
{
    for (int i = 0; i < size; i++) {
        if (&a[i] == left || &a[i] == right) {
            printf("\"%d\" ", a[i]);
        } else {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

static int *partition(int *left, int *right, int pivot)
{
    int *original_left = left;
    int size = right - original_left + 1;

    while (left <= right) {
        while (*left < pivot)
            ++left;
        while (*right >= pivot)
            --right;
        if (left < right) {
            printf("Pivot: %d\n", pivot);
            print_array(original_left, size, left, right);
            printf("Swapping %d and %d\n", *left, *right);
            swap(*left, *right);
            ++left;
            --right;
            print_array(original_left, size, left, right);
        }
    }
    return left;
}