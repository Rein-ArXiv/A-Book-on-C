/* Chapter 3 exercise 5 */

/* 2의 거듭제곱 목록을 10진수, 16진수, 8진수로 출력하는 프로그램을 다음 코드를
 * 사용하여 완성하여라.

    int i, val =1;
    for (i = 0; i < 35; ++i){
        printf("%15d%15u%15x%15o\n", val, val, val, val);
        val *= 2;
    }

 * 무엇이 출력되는지를 보고 설명하여라. 2의 거듭제곱을 16진수나 8진수 표기법으
 * 로 표현하면 특별한 특성을 가진다. 어떤 특성인가?
 */

#include <stdio.h>

int main(void)
{
    int i, val = 1;

    for (i = 0; i <35; ++i){
        printf("%15d%15u%15x%15o\n", val, val, val, val);
        val *= 2;
    }
    
    return 0;
}