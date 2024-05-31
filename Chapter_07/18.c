/* Chapter 7 exercise 18 */

/* 4.10절 "예제: 부울 변수"에서 제시한 프로그램을 다시 작성하여라. 이때, char 형
 * 변수 b의 하위 5개 비트를 사용하여 5개의 부울 변수 b1, ..., b5를 나타내도록
 * 하여라.
 */


#include <stdio.h>

int main(void)
{
    char b = 0b00;
    int cnt = 0;

    printf("\n%5s%5s%5s%5s%5s%5s%7s%7s%11s\n\n", // headings
        "Cnt", "b1", "b2", "b3", "b4", "b5",
        "fct1", "fct2", "majority");
    
    for(int i=0; i<32; i++){
        int b1 = (b >> 0) & 0x01;
        int b2 = (b >> 1) & 0x01;
        int b3 = (b >> 2) & 0x01;
        int b4 = (b >> 3) & 0x01;
        int b5 = (b >> 4) & 0x01;

        printf("%5d%5d%5d%5d%5d%5d%6d%7d%9d\n",
                            ++cnt, b1, b2, b3, b4, b5,
                            b1 || b3 || b5, b1 && b2 || b4 && b5,
                            b1 + b2 + b3 + b4 + b5 >= 3);
        b++;
    }

    putchar('\n');
    return 0;
}