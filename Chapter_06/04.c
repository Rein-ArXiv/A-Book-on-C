/* Chapter 6 exercise 4 */

/* i와 j는 int 형이고, p와 q는 int 형 포인터라면, 다음의 배정 수식 중 잘못된
 * 것은 어느 것인가?

    p = &i      p = &*&i        i = (int) p     q = &p
    *q = &j     i = (*&)j       i = *&*&j       i = *p++ + *q

 */

#include <stdio.h>

int main(void)
{
    int *p, *q, i, j;
    
    i = 1, j = 2;

    p = &i;
    printf("%p %d\n", p, i);

    p = &*&i;
    printf("%p %d\n", p, i);

    i = (int) p;                // warning: cast from pointer to integer of different size
    printf("%p %d\n", p, i);

    q = &p;                     // warning: assignment to 'int *' from incompatible pointer type 'int **'
    printf("%p %p\n", p, q);

    *q = &j;                    // warning: assignment to 'int' from 'int *' makes integer from pointer without a cast
    printf("%p %d\n", q, j);

    //i = (*&)j;                  // error

    i = *&*&j;
    printf("%d %d\n", i, j);

    i = *p++ + *q;
    printf("%d %d\n", i, j);

    return 0;
}