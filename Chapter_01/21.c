/* Chapter 1 exercise 21 */

/* 연습 문제 19번의 프로그램은 수행 결과가 입력에 따라 다르게 나왔다.
 * 다음 코드를 포함하는 프로그램을 작성하여라.
 
    char c1, c2, c3;
    int cnt;
    
    printf("Input three characters : ");
    cnt = scanf("%c%c%c", &c1, &c2, &c3);
    printf("Number of successful conversions : %d\n", cnt);
   
 * 다양하게 입력해 보고, 각 경우의 출력 값을 써라. 힌트: 연습 문제 19번에서
 * 작성한 프로그램이 출력한 숫자를 여기서도 출력할 수 있다. 하지만 그런 숫자가
 * 출력되도록 하기 위해서는 더 많은 노력이 필요하다.
 */

#include <stdio.h>

int main(void)
{
    char c1, c2, c3;
    int cnt;
    
    printf("Input three characters : ");
    cnt = scanf("%c%c%c", &c1, &c2, &c3);
    printf("Number of successful conversions : %d\n", cnt);
    return 0;   
}