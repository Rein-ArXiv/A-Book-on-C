/* Chapter 5 exercise 18 */

/* 두 양의 정수의 최대 공약수는 두 수의 공통 약수 중 가장 큰 수이다. 예를 들어,
 * 3은 6과 15의 최대 공약수이고, 1은 15와 22의 최대 공약수이다. 다음은 두 양의
 * 정수의 최대 공약수를 계산하는 재귀적 함수이다.
 
    int gcd(int p, int q)
    {
        int r;
        
        if ((r = p % q) == 0)
            return q;
        else
            return gcd(q, r);
    }

 * 먼저 이 함수를 검사하는 프로그램을 작성하여라. 그리고, 이 함수와 같은 일을
 * 하는 반복적 함수를 작성한 후 검사해 보아라.
 */

#include <stdio.h>

int gcd(int p, int q);
int repeat_gcd(int p, int q);

int main(void)
{
    int p, q;

    printf("Input p and q: ");
    scanf("%d %d", &p, &q);

    printf("GCD of %d and %d (recursive function): %d\n", p, q, gcd(p, q));
    printf("GCD of %d and %d (iterative function): %d\n", p, q, (repeat_gcd(p, q)));

    return 0;

}

int gcd(int p, int q)
{
    int r;
    
    if ((r = p % q) == 0)
        return q;
    else
        return gcd(q, r);
}


int repeat_gcd(int p, int q)
{
    int r = p % q;

    while (r != 0){
        r = p % q;
        p = q;
        q = r;
    }
    return p;
}
