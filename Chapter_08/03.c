/* Chapter 8 exercise 3 */

/* 프로그램에서 x, y, z는 float 형 변수라고 가정하자. 이 변수들이 각각 1.1, 2.2,
 * 3.3을 가진다고 하고, 다음 문장을 보자.
 
    PRN3(x, y, z);

 * 이것이 다음과 같은 출력을 내도록 PRN3() 매크로를 정의하여라.

    x has value 1.1 and y has value 2.2 and z has value 3.3

 */

#include <stdio.h>

#define PRN3(x, y, z) printf("x has value %.1f and y has value %.1f and z has value %.1f\n", x, y, z);

int main(void)
{
    float x = 1.1f, y = 2.2f, z = 3.3f;

    PRN3(x, y, z);
    return 0;
}
