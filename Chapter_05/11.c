/* Chapter 5 exercise 11 */

/* n이 소수이면 1을 리턴하고, 아니면 0을 리턴하는 int is_prime(n) 함수를 작성
 * 하여라. 힌트: 양의 정수 k와 n에 대해서, n이 k로 나누어질 필요충분 조건은 n %
 * k의 값이 0인 것이다.
 */

#include <stdio.h>

int is_prime(int n);

int main(void)
{
    int n;

    printf("Input n: ");
    scanf("%d", &n);

    if (is_prime(n))
        printf("%d is prime.\n", n);
    else
        printf("%d is not prime.\n", n);

    return 0;
}

int is_prime(int n)
{
    int prime = 1;
    for (int i = 2; i < n; i++){
        if (n % i == 0){
            prime = 0;
        }
    }
    return prime;
}