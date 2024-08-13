/* Chapter 4 exercise 19 */

/* 다음 코드는 인터럽트가 걸릴 때까지 화면에 TRUE FOREVER를 반복적으로 출력하
 * 는 것이다. (UNIX에서 인터럽트는 control-c를 입력하면 된다.)

    while (1)
        printf(" TRUE FOREVER ");

 * while 문 대신에 for 문을 사용하여 같은 작업을 수행하는 간단한 프로그램을
 * 작성하여라. for 문의 몸체에는 공백 문장 ";"만 포함해야 한다.
 */

#include <stdio.h>

int main(void)
{
    for (;;){
        printf(" TRUE FOREVER");
    }
}