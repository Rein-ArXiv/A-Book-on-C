/* Chapter 8 exercise 4 */

/* 다음 코드가 a_b_c.h 파일에 있다고 가정하자.

    #define    TRUE    1                        
    #define    A_B_C                            \
            
    int main(void)                              \
    {                                           \
        printf("A Big Cheery \"hello\"!\n");    \
        return 0;                               \
    }                                           

 * 그리고 다음 코드가 a_b_c.c 파일에 있다고 가정하자.

    #if TRUE
        #include <stdio.h>
        #include "a_b_c.h"
        A_B_C
    #endif

 * 이 프로그램을 컴파일하면, 컴파일러는 오류를 발생한다. 그 이유를 설명하여라.
 * 이 두 파일 중 한 파일에 있는 두 행을 변경하여, 프로그램이 컴파일되고 실행될
 * 수 있도록 할 수 있는가? 그 이유를 설명하여라.
 */