/* Chapter 3 exercise 13 */

/* 다음 표는 대부분의 컴퓨터에서 기본형을 저장하는 데 필요한 바이트 수를 보여
 * 주고 있다. 사용자 컴퓨터에서의 값은 어떻게 되는가? 표를 완성하는 프로그램
 * 작성하고 실행해 보아라.

    기본형          사용자 컴퓨터에서 요구되는 메모리 (byte)
    char
    short
    int
    unsigned
    long
    float
    double
    long double

 */


#include <stdio.h>

int main(void)
{
    char c = 0;
    short sh = 0;
    int i = 0;
    unsigned u = 0;
    long l = 0;
    float f = 0.0f;
    double d = 0.0;
    long double ld = 0.0;

    printf("Size of Datatypes\n");
    printf("char=%zd\nshort=%zd\nint=%zd\nunsigned=%zd\nlong=%zd\nfloat=%zd\ndouble=%zd\nlong double=%zd\n",
    sizeof(c), sizeof(sh), sizeof(i), sizeof(u), sizeof(l), sizeof(f), sizeof(d), sizeof(ld));
    return 0;
}