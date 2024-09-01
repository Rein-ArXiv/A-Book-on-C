/* Chapter 10 exercise 17 */

/* 다음과 같은 폴리시 수식을 계산하여라.

    7, 6, -, 3, *
    9, 2, 3, *, 4, -, +
    1, 2, +, 3, 4, +, *

 */

/* (7 - 6) * 3 = 1
 * 9 + ((2 * 3) - 4) = 11
 * (1 + 2) * (3 + 4) = 21
 */

#include "polish/polish.h"

int main(void)
{
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
    return 0;
}