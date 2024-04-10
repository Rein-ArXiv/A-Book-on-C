/* Chapter 4 exercise 14 */

/* putchar() 함수는 출력한 문자의 값을 int 형으로 리턴한다. 다음 코드는 어떤
 * 값을 출력하겠는가?
    
    for (putchar('1'); putchar('2'); putchar('3'))
        putchar('4');

 */

#include <stdio.h>

int main(void)
{
    for (putchar('1'); putchar('2'); putchar('3'))
        putchar('4');

    return 0;
}
