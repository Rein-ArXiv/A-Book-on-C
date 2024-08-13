/* Chapter 4 exercise 17 */

/* 첫 n 개의 짝수의 합과 첫 n 개의 홀수의 합을 계산하는 3개의 프로그램을 작성
 * 하여라. n 값은 사용자가 입력하도록 하여라. 첫 번째 프로그램에서는 다음 코드
 * 를 사용하여라.
  
    for (cnt = 0, i = 1, j = 2; cnt < n; ++cnt, i += 2, j += 2)
        odd_sum += i, even_sum += j;

 * 이 코드는 콤마 연산자를 많이 사용하고 있음을 알 수 있다. 이렇게 사용하는 것
 * 이 좋은 코드는 아니지만, 콤마 연산자의 사용 방법을 알려주고 있다. 두 번째 프
 * 로그램에서는 콤마 연산자를 사용하지 말고 하나 이상의 for 문을 사용하여라.
 * 세 번재 프로그램에서는 while 문만을 사용하여라.
 */

#include <stdio.h>

int main(void)
{
    int i, j, n;
    int cnt;
    int odd_sum = 0, even_sum = 0;

    printf("Input n and press Enter: ");
    scanf("%d", &n);

    // First program
    for (cnt = 0, i = 1, j = 2; cnt < n; ++cnt, i += 2, j += 2)
        odd_sum += i, even_sum += j;
    printf("Odd sum: %d\t Even Sum: %d\n", odd_sum, even_sum);

    // Second program
    
    i = 1, j = 2;
    odd_sum = 0, even_sum = 0;
    for (cnt = 0; cnt < n; ++cnt){
        odd_sum += i;
        even_sum += j;
        i += 2;
        j += 2;
    }
    printf("Odd sum: %d\t Even Sum: %d\n", odd_sum, even_sum);

    // Third program

    cnt = 0;
    i = 1, j = 2;
    odd_sum = 0, even_sum = 0;

    while (cnt < n){
        odd_sum += i, even_sum += j;
        i += 2;
        j += 2;
        ++cnt;
    }

    printf("Odd sum: %d\t Even Sum: %d\n", odd_sum, even_sum);
    return 0;
}