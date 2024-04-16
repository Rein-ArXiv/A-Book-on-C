/* Chapter 4 exercise 18 */

/* 연습 문제 17번에서 작성한 프로그램 중 하나에 다음 코드를 삽입하여 다시 작성
 * 하여라.
  
    do {
        printf("Input a positive integer: ");
        scanf("%d", &n);
        if (error = (n <= 0))
            printf("\nERROR : Do it again!\n\n");
    } while (error);

 * 그리고 이 do 문을 사용하는 대신 while 문을 사용하여 같은 결과가 나오도록
 * 수정하여라.
 */

#include <stdio.h>

int main(void)
{
    int i, j, n;
    int cnt, error = 1;
    int odd_sum = 0, even_sum = 0;

    
    do {
        printf("Input a positive integer: ");
        scanf("%d", &n);
        if (error = (n <= 0))
            printf("\nERROR : Do it again!\n\n");
    } while (error);
    
    /*
    while (error) {
        printf("Input a positive integer: ");
        scanf("%d", &n);
        if (error = (n <= 0))
            printf("\nERROR : Do it again!\n\n");
    }
    */

    for (cnt = 0, i = 1, j = 2; cnt < n; ++cnt, i += 2, j += 2)
        odd_sum += i, even_sum += j;
    printf("Odd sum: %d\t Even Sum: %d\n", odd_sum, even_sum);

    return 0;
}