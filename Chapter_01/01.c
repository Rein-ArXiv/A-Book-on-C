/* Chapter 1 exercise 1 */

/* 화면에 다음 단어들을 아래 조건에 맞게 출력하여라 
 * she sells sea shells by the seashore
 * (a) 한 줄에
 * (b) 세 줄에
 * (c) 네모 안에
 */

#include <stdio.h>

int main(void)
{
    printf("(a) she sells sea shells by the seashore\n\n");
    printf("(b) she sells\nsea shells\nby the seashore\n\n");
    printf("(c) *********************\n");
    printf("    * she sells         *\n");
    printf("    * sea shells by the *\n");
    printf("    * seashore          *\n");
    printf("    *********************\n");
    return 0;
}