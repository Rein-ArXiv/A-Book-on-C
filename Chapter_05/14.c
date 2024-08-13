/* Chapter 5 exercise 14 */

/* 주어진 숫자에 대한 모든 인수를 찾는 함수를 작성하여라. 예를 들면, 다음과 같
 * 다.

    9 = 3 * 3, 17 = 17(소수), 52 = 2 * 2 * 13

 * 작은 숫자의 인수를 찾는 것은 쉽고, 인수를 찾는 프로그램을 작성하는 것도 문
 * 제가 없을 것이다. 그러나, 일반적으로 인수를 구하는 것은 매우 어렵다. 몇백 자
 * 리로 이루어진 정수의 인수를 찾는 것은 대형 컴퓨터를 사용해도 불가능하다.
 */

#include <stdio.h>

long long int is_prime(long long int n);

int main(void)
{
    long long int n, i, factor;

    printf("Input number: ");
    scanf("%lld", &n);

    printf("%lld = ", n);

    while(n > 1){        
        for (i = 2; i * i <= n; i++) {
            if ((n % i == 0) && is_prime(i)){
                n /= i;
                printf("%lld", i);

                if (n > 1){
                    printf(" * ");
                }
                break;
            }
        }

    }
    putchar('\n');

    return 0;
}

long long int is_prime(long long int n)
{
    int prime = 1;
    
    if (n == 1) return 0;

    for (long long int i = 2; i < n; i++){
        if (n % i == 0){
            prime = 0;
        }
    }
    return prime;
}