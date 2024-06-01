/* Chapter 7 exercise 28 */

/* 집합에 대한 수학적 개념의 유용한 구현은 unsigned long을 최대 32개의 원소로
 * 구성된 집합으로 다루는 것이다.

    typedef unsigned long set;
    const set empty = 0x0;      // use hexdecimal constants

 * 비트 연산자를 사용하여 두 집합을 합하는 루틴을 작성하여라. 주의: union은 키
 * 워드이므로, 다른 이름을 사용하여라.
 
    // This function returns the union of a and b.
    set Union(set a, set b);

 * 마스크를 사용하면 원하는 비트가 1인지를 검사할 수 있다. 이 아이디어를 이용
 * 하여 집합의 구성 원소들을 출력하는 다음과 같은 함수 원형을 갖는 함수를 작성
 * 하여라.
 
    void display(set a);
 
 * 이 함수를 검사하기 위해 다음 코드를 사용할 수 있을 것이다.

    set a = 0x7;                // a has elements 1, 2, 3
    set b = 0x55;               // b has elements 1, 3, 5, 7

    display(Union(a, b));       // 1, 2, 3, 5, 7 is the union

 */

#include <stdio.h>

typedef unsigned long set;
const set empty = 0x0;

set Union(set a, set b){
    return a | b;
}

void display(set a){
    printf("{ ");
    for(int i=0; i<32; i++){
        if((a >> i) & 1){
            printf("%d ", i + 1);
        }
    }
    printf("}\n");
}

int main(void)
{
    set a = 0x7;
    set b = 0x55;

    display(Union(a, b));
    return 0;
}

