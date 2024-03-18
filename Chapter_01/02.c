/* Chapter 1 exercise 2 */

/* 1.3절에 있는 marathon 프로그램의 결과가 옳은지 계산기를 사용하여 확인하여라.
 * 이 프로그램에서 실수형 상수 1760.0을 정수형 상수 1760으로 수정하여라.
 * 이 수정된 프로그램을 컴파일한 후 실행하여 그 결과가 수정하기 전의 것과
 * 같지 않음을 확인하여라. 정수 나눗셈은 소숫점 이하 부분을 버리기 때문에
 * 그 결과가 달라진다.
 */

/* marathon.c */

#include <stdio.h>

int main(void)
{
    int miles, yards;
    float kilometers;
    
    miles = 26;
    yards = 385;
    kilometers = 1.609 * (miles + yards / 1760); /* Changed 1760.0 -> 1760 */
    printf("\nA marthon is %f kilometers. \n\n", kilometers); /* 42.185970 -> 41.834000 */
    return 0;
}