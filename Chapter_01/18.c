/* Chapter 1 exercise 18 */

/* 이 연습 문제는 형 한정자인 const에 관한 것이다. 컴파일러는 다음 코드를
 * 어떻게 다루겠는가?

    const int a = 0;
    a = 333;
    printf("%d\n", a);

 */

#include <stdio.h>

int main(void)
{
    const int a = 0;
    a = 333;            // error: assignment of read-only variable 'a'
    printf("%d\n", a);
    return 0;
}