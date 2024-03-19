/* Chapter 3 exercise 14 */

/* 'A'와 같은 문자 상수의 형은 C에서는 int 형이고 C++에서는 char 형이다. 다
 * 음 프로그램을 먼저 C 로 컴파일하고, 그 다음 C++로 컴파일하여라. 각 경우에
 * 어떻게 출력되는가?

    #include <stdio.h>

    int main(void)
    {
        printf("sizeof('A') = %u\n", sizeof('A'));
        return 0;
    }
    
 */


#include <stdio.h>

int main(void)
{
    printf("sizeof('A') = %u\n", sizeof('A')); // 4
    return 0;
}