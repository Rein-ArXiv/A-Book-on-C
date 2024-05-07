/* Chapter 6 exercise 8 */

/* 다음 프로그램은 어떤 값을 출력하는가? 설명하여라.

    #include <stdio.h>

    typedef unsigned long ulong;

    int main(void)
    {
        char *pc = NULL;
        int *pi = NULL;
        double *pd = NULL;
        long double *pld = NULL;

        printf("%5lu%5lu\n%5lu%5lu\n%5lu%5lu\n",
                (ulong)(pc + 1), (ulong)(pi + 1),
                (ulong)(pd + 1), (ulong)(pld + 1),
                (ulong)(pc + 3), (ulong)(pld + 3));
        return 0;
    }

 */

#include <stdio.h>

typedef unsigned long ulong;

int main(void)
{
    char *pc = NULL;
    int *pi = NULL;
    double *pd = NULL;
    long double *pld = NULL;

    printf("%5lu%5lu\n%5lu%5lu\n%5lu%5lu\n",
            (ulong)(pc + 1), (ulong)(pi + 1),
            (ulong)(pd + 1), (ulong)(pld + 1),
            (ulong)(pc + 3), (ulong)(pld + 3));
    return 0;
}
