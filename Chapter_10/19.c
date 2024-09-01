/* Chapter 10 exercise 19 */

/* 10.6 절의 polish 프로그램을 사용하여 연습문제 17번과 18번의 6개의 폴리시 수
 * 식을 계산하여라.
 */

#include "polish/polish.h"

int main(void)
{
    printf("Exercise 17:\n");

    char str1[] = "7, 6, -, 3, *";
    char str2[] = "9, 2, 3, *, 4, -, +";
    char str3[] = "1, 2, +, 3, 4, +, *";
    stack polish;
    
    printf("\n%s%s\n\n", "Polish expression: ", str1);
    fill(&polish, str1);         // fill stack from string
    prn_stack(&polish);
    printf("\n%s%d\n\n", "Polish evaluation: ", evaluate(&polish));

    printf("\n%s%s\n\n", "Polish expression: ", str2);
    fill(&polish, str2);         // fill stack from string
    prn_stack(&polish);
    printf("\n%s%d\n\n", "Polish evaluation: ", evaluate(&polish));
    
    printf("\n%s%s\n\n", "Polish expression: ", str3);
    fill(&polish, str3);         // fill stack from string
    prn_stack(&polish);
    printf("\n%s%d\n\n", "Polish evaluation: ", evaluate(&polish));
    putchar('\n');

    printf("Exercise 18:\n");
    
    return 0;
}