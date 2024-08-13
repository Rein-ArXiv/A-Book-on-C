/* Chapter 9 exercise 22 */

/* 4.10절에서 부울 함수에 대한 값의 표를 출력하는 프로그램을 작성하였다. 이 프
 * 로그램을 비트 필드를 사용하여 다시 작성해 보아라. 이때 각 부울 변수로 1비트
 * 필드를 사용하여라.
 */

#include <stdio.h>

#define T 1
#define F 0

typedef struct BoolFields {
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b3 : 1;
    unsigned int b4 : 1;
    unsigned int b5 : 1;    
} BoolFields;

int fct1(BoolFields b) {
    return b.b1 | b.b3 | b.b5;
}

int fct2(BoolFields b) {
    return b.b1 & b.b2 || b.b4 & b.b5;
}

int fct3(BoolFields b) {
    return b.b1 + b.b2 + b.b3 + b.b4 + b.b5 >= 3;
}

int main(void) {
    BoolFields b;
    unsigned int cnt = 0; 

    printf("\n%5s%5s%5s%5s%5s%5s%7s%7s%11s\n\n",
           "Cnt", "b1", "b2", "b3", "b4", "b5", "fct1", "fct2", "majority");


    for (int i = 0; i < 32; ++i){
        b.b1 = (i & 0x01) >> 0;
        b.b2 = (i & 0x02) >> 1;
        b.b3 = (i & 0x04) >> 2;
        b.b4 = (i & 0x08) >> 3;
        b.b5 = (i & 0x10) >> 4;

        ++cnt;
        printf("%5u%5u%5u%5u%5u%5u%7u%7u%7u\n",
            cnt, b.b1, b.b2, b.b3, b.b4, b.b5,
            fct1(b),
            fct2(b),
            fct3(b));
    }

    return 0;
}
