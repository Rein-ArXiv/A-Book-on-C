/* Chapter 6 exercise 15 */

/* bubble() 함수를 수정하여 아무런 원소도 교환되지 않으면 종료하도록 하여라. 
 */

#include <stdio.h>
#include <stdlib.h>


void swap(int *p, int *q);
void bubble(int a[], int n);

int main(void)
{
    int a[5] = {5, 4, 1, 2, 3};
    bubble(a, 5);

    return 0;
}

void swap(int *p, int *q)
{
    int tmp;

    tmp = *p;
    *p = *q;
    *q = tmp;
}

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
                printf("Swap %d and %d\n", a[j-1], a[j]);
            }
        }
        
        if (sorted) {
            printf("All sorted. Check count %d. End.\n", cnt);
            return;
        }
    }
    printf("Sort end. Count %d. End.\n", cnt);
}