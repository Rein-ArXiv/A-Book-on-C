/* Quicksort on string! Pointer version with macros. */
#include <string.h>

#define swap(x, y)  { char* t = x; x = y; y = t; }
#define order(x, y) if (strcmp(x, y) > 0) swap (x, y)
#define o2(x, y)    order(x, y)
#define o3(x, y, z) o2(x, y); o2(x, z); o2(y, z)

typedef enum {yes, no} yes_no;

static yes_no find_pivot(char **left, char **right, char **pivot_ptr);
static char   **partition(char **left, char **right, char *pivot);

void quicksort(char **left, char **right)
{
    char **p, *pivot;

    if (find_pivot(left, right, &pivot) == yes) {
        p = partition(left, right, pivot);
        quicksort(left, p - 1);
        quicksort(p, right);
    }
}

static yes_no find_pivot(char **left, char **right, char **pivot_ptr)
{
    char *a = *left;                            // left value
    char *b = *(left + (right - left) / 2);     // middle value
    char *c = *right;                           // right value

    o3(a, b, c);

    if (strcmp(a, b) < 0) {
        *pivot_ptr = b;
        return yes;
    }
    if (strcmp(b, c) < 0) {
        *pivot_ptr = c;
        return yes;
    }

    for (char **p = left + 1; p <= right; ++p){
        if (strcmp(*p, *left) != 0) {
            *pivot_ptr = (strcmp(*p, *left) < 0) ? *left : *p;
            return yes;
        }
    }
    return no;      // all elements have the same value
}

static char **partition(char **left, char **right, char *pivot)
{
    while (left <= right) {
        while (strcmp(*left, pivot) < 0)
            ++left;
        while (strcmp(*right, pivot) >= 0)
            --right;
        if (left < right) {
            swap(*left, *right);
            ++left;
            --right;
        }
    }
    return left;
}