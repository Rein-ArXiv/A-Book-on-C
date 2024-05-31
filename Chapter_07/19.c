/* Chapter 7 exercise 19 */

/* 연습 문제 18번에서 작성한 프로그램을 컴퓨터의 산술연산을 이용하여 다시 작성
 * 하여라. 손으로 b의 비트 표현에 1을 더하는 것은 중첩된 for 문을 사용하는 것
 * 과 같은 효과를 가져옴을 보여라. 이 연습 문제에서 작성되는 프로그램은 하나의
 * 중첩되지 않는 for 문을 사용하여 표를 생성하여야 한다.
 */

#include <stdio.h>
#include <stdbool.h>

bool fct1(bool b1, bool b2, bool b3, bool b4, bool b5) {
    return b1 || b3 || b5;
}

bool fct2(bool b1, bool b2, bool b3, bool b4, bool b5) {
    return (b1 && b2) || (b4 && b5);
}

int main(void) {
    unsigned char b;
    int cnt = 0;

    printf("\n%5s%5s%5s%5s%5s%7s%7s%11s\n\n",
           "Cnt", "b1", "b2", "b3", "b4", "b5", "fct1", "fct2", "majority");

    for (b = 0; b < 32; b++) {
        bool b1 = (b >> 0) & 1;
        bool b2 = (b >> 1) & 1;
        bool b3 = (b >> 2) & 1;
        bool b4 = (b >> 3) & 1;
        bool b5 = (b >> 4) & 1;
        
        bool result1 = fct1(b1, b2, b3, b4, b5);
        bool result2 = fct2(b1, b2, b3, b4, b5);
        bool majority = (b1 + b2 + b3 + b4 + b5 >= 3);

        printf("%5d%5d%5d%5d%5d%5d%7d%7d%11d\n",
               ++cnt, b1, b2, b3, b4, b5, result1, result2, majority); 
    }

    putchar('\n');
    return 0;
}
