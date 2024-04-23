/* Chapter 5 exercise 16 */

/* 5.14절의 "The universe is never ending!" 프로그램을 수정하여 17번 호출한
 * 후 종료하도록 하여랴. 수정한 프로그램은 하나의 main() 함수만으로 구성되어야
 * 하며, 재귀 호출을 해야 한다. 힌트: 정적 변수를 사용하여라.
 */

#include <stdio.h>

static int ending = 18;

int main(void)
{
    ending--;
    while (ending > 0){
        printf(" The universe is never ending! ");
        main(); 
    }
    return 0;
}