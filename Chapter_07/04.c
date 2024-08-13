/* Chapter 7 exercise 4 */

/* 각자의 컴퓨터에서 부호 비트가 삽입되는지를 실험해 보아라. 다음 코드는 이것을
 * 알 수 있도록 도와준다. 이 코드가 왜 그것을 수행하는지 설명하여라.

    int         i = -1;     // turn all bits on
    unsigned    u = -1; 

    if (i >> 1 == u >> 1)
        printf("Zeros are shifted in.\n");
    else
        printf("Sign bits are shifted in.\n");

 */

#include <stdio.h>

int main(void){
    int         i = -1;     // turn all bits on
    unsigned    u = -1; 

    if (i >> 1 == u >> 1)
        printf("Zeros are shifted in.\n");
    else
        printf("Sign bits are shifted in.\n");

    return 0;
}