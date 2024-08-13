/* Quicksort which finds pivot in 2 numbers! Pointer version with macros. */

#define swap(x, y)  { int t = x; x = y; y = t; }
#define order(x, y) if (x > y) swap (x, y)
#define o2(x, y)    order(x, y)
#define o3(x, y, z) o2(x, y); o2(x, z); o2(y, z)

typedef enum {yes, no} yes_no;

static yes_no find_pivot(int *left, int *right, int *pivot_ptr);
static int *partition(int *left, int *right, int pivot);

int cnt = 0;  // 전역 변수로 cnt 선언

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
    int a, b, *p;

    a = *left;                          // left value
    b = *right;                         // right value
    o2(a, b);

    if (a < b) {    // pivot will be higher of 2 values
        *pivot_ptr = b;
        return yes;
    }

    for (p = left + 1; p <= right; ++p)
        if (*p != *left) {
            *pivot_ptr = (*p < *left) ? *left : *p;
            return yes;
        }
    return no;      // all elements have the same value
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
