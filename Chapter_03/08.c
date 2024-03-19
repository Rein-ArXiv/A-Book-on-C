/* Chapter 3 exercise 8 */

/* 수학에서 $epsilon$은 가장 작은 양수를 나타내는 데 사용된다. 수학에서는 임의의 작은
 * 이라는 것이 가능하지만, 컴퓨터에서는 "임의의 작은"이라는 개념이 없다. 수치
 * 해석에서는 double 형의 변수 eps(epsilon)을 선언하고, 다음 식을 만족하는
 * 가장 작은 양수를 eps에 할당하는 것이 편리할 때가 있다.
 
    1.0 < 1.0 + eps

 * 이 수치는 컴퓨터에 종속적이다. 사용자의 컴퓨터에서 이 eps 값을 구해 보아라.
 * eps 값을 1e-37에서부터 시작하여 보아라. 이 값에 대해서 위의 식은 거짓이다.
 */

#include <stdio.h>

int main(void)
{
    double eps = 1.0e-37;
    
    while (1.0 + eps <= 1.0) {
        eps *= 10.0;
    }

    printf("eps가 %e일 때 가장 작은 양수를 만족한다.\n", eps);
    return 0;
}