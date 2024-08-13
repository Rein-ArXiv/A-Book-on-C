/* Chpater 6 exercise 22 */

/* 다음 코드가 출력하는 것을 적어보고, 설명하여라.
 
    printf("%c%c%c%c%c!\n",
        "ghi"[1], *("def" + 1),
        *"abc" + 11, "klm"[1], *"ghi" + 8);
        
 */

#include <stdio.h>

int main(void)
{
    printf("%c%c%c%c%c!\n",
    "ghi"[1], *("def" + 1),
    *"abc" + 11, "klm"[1], *"ghi" + 8);
    return 0;
}