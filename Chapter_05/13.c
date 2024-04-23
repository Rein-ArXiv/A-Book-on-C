/* Chapter 5 exercise 13 */

/* Goldbach 추측이라고 하는 유명한 추측은 "2보다 큰 모든 짝수는 두 개의 소수의
 * 합으로 표현될 수 있다"라는 것이다. 이 추측을 검사하기 위해 컴퓨터를 많이 사
 * 용하고 있다. 반례는 아직 발견되지 않았다. 기호 상수 START와 FINISH 사이의
 * 모든 짝수에 대하여 이 추측이 맞는지 검사하는 프로그램을 작성하여라. 예를 들
 * 어, 다음과 같이 선언했다고 하자.
 
    #define     START   700
    #define     FINISH  1100

 * 그러면, 출력은 다음과 같이 나오도록 프로그램을 작성하여라.

    Every even number greater than 2 is the sum of two primes :

        700 = 17 + 683
        702 = 11 + 691
        704 =  3 + 701
        .....
        1098 = 5 + 1093
        1100 = 3 + 1097

    힌트: 연습 문제 11번에서 작성한 is_prime() 함수를 사용하여라.

 */

#include <stdio.h>

#define     START   700
#define     FINISH  1100

int is_prime(int n);

int main(void)
{
    int i, j;

    for (i = START; i < FINISH; i += 2){
        if (i % 2 != 0){
            i++;
            continue;
        }

        for (j = i; j > 1; j--){
            if (is_prime(j)){
                if (is_prime(i-j)){
                    printf("%d = %d + %d\n", i, i-j, j);
                    break;
                }
            }
        }
    }

    return 0;
}

int is_prime(int n)
{
    int prime = 1;
    if (n == 1) return 0;

    for (int i = 2; i < n; i++){
        if (n % i == 0){
            prime = 0;
        }
    }
    return prime;
}