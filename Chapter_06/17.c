/* Chpater 6 exercise 17 */

/* p가 포인터라면, *p++와 (*p)++은 다르다. 다음 코드의 출력 결과는 무엇이겠는
 * 가? 설명하여라.

    char a[] = "abc";
    char *p;
    int i;

    p = a;
    for (i = 0; i < 3; ++i)
        printf("%c\n", *p++);
    printf("a = %s\n", a);
    p = a;
    for (i = 0; i < 3; ++i)
        printf("%c\n", (*p)++);
    printf("a = %s\n", a);

 */

#include <stdio.h>

int main(void)
{
    char a[] = "abc";
    char *p;
    int i;

    p = a;
    for (i = 0; i < 3; ++i)
        printf("%c\n", *p++);       // p = p + 1
    printf("a = %s\n", a);

    p = a;
    for (i = 0; i < 3; ++i)
        printf("%c\n", (*p)++);     // (*p) = (*p) + 1
    printf("a = %s\n", a);
    
    return 0;    
}