/* Chapter 5 exercise 3 */

/* 다음 프로그램의 출력을 쓰고, 그 이유를 설명하여라.

    #include <stdio.h>

    int z;

    void f(int x)
    {
        x = 2;
        z += x;
    }

    int main(void)
    {
        z = 5;
        f(z);
        printf("z = %d\n", z);
        return 0;
    }

 */

#include <stdio.h>

int z;

void f(int x)
{
    x = 2;
    z += x; 
}

int main(void)
{
    z = 5;
    f(z);   // z = 7
    printf("z = %d\n", z);
    return 0;
}