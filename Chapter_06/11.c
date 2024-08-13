/* Chapter 6 exercise 11 */

/* 다음 프로그램은 무엇이 잘못되었는가? 프로그램을 올바르게 수정하고, 출력 값의
 * 의미를 설명하여라.

    #include <stdio.h>

    int main(void)
    {
        int a[] = {0, 2, 4, 6, 8},
            *p = a + 3;
        
        printf("%s%d%s\n%s%d%s\n",
            "a[?]   = ", *p, "?",
            "a[?+1] = ", *p + 1, "?");
        return 0;
    }

 */

#include <stdio.h>

int main(void)
{
    int a[] = {0, 2, 4, 6, 8},
        *p = a + 3;
    
    printf("%s%d%s\n%s%d%s\n",
        "a[?]   = ", *p, "?",
        "a[?+1] = ", *(p + 1), "?");
    return 0;
}