/* Chapter 4 exercise 12 */

/* 4.8절 "while 문"에서 n이 음수이면, 다음 while 문은 무한 루프가 된다고 하였
 * 다.

    while (--n)
        .....   // do something

 * 그러나 실제적으로 이것은 컴퓨터에 종속적이다. 그 이유를 설명해 보아라.
 */

#include <stdio.h>
#include <limits.h>

int main(void){
    int n = INT_MIN;

    printf("Loop start. n: %d\n", n);
    while(--n){

    }

    printf("Loop out. n: %d\n", n);
    return 0;
}