/* Chapter 1 exercise 3 */

/* marathon 프로그램의 모든 상수와 변수를 double 형으로 수정하여라.
 * 이 수정된 프로그램의 결과가 원래 프로그램의 결과와 같은가?
 */

#include <stdio.h>

int main(void)
{
    double miles, yards;
    double kilometers;
    
    miles = 26;
    yards = 385;
    kilometers = 1.609 * (miles + yards / 1760.0);
    printf("\nA marthon is %f kilometers. \n\n", kilometers); /* 42.185970 -> 42.185969 changed */
    return 0;
}