/* Chapter 5 exercise 12 */

/* n번째 Fibonacci 수가 소수인가를 검사하는 is_fib_prime(n) 함수를 작성하여
 * 라. 이 함수는 두 함수를 호출해야 한다. 하나는 4.13절에서 소개한 반복적 함수인
 * fibonacci()이고, 다른 하나는 앞의 연습 문제에서 작성한 is_prime() 함수이
 * 다. 3과 10 사이의 n에 대해, n번째 fibonacci 수가 소수일 필요 충분 조건은 n이
 * 소수인 것이다. n이 10보다 클 때 is_fib_prime() 함수는 어떻게 동작하는지 조
 * 사하여라.
 */

#include <stdio.h>

int fibonacci(int n);
int is_prime(int n);
int is_fib_prime(int n);

int main(void)
{
    int i;
    for (i = 1; i < 30; i++) {
        is_fib_prime(i);
    }

    return 0;
}

int fibonacci(int n)
{
    int cnt, tmp, f0 = 1, f1 = 1;


    for (cnt = 2; cnt < n; cnt++){
        tmp = f1;
        f1 += f0;
        f0 = tmp;
    }

    return f1;
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

int is_fib_prime(int n)
{
    int fib_num, fib_num_is_prime;

    fib_num = fibonacci(n);
    fib_num_is_prime = is_prime(fib_num);

    if (fib_num_is_prime)
        printf("%d-th fibonacci num %d is prime.\n", n, fib_num);
    else
        printf("%d-th fibonacci num %d is not prime.\n", n, fib_num);
    return fib_num_is_prime;
}