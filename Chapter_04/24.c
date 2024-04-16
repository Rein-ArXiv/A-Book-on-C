/* Chapter 4 exercise 24 */

/* a, b, c 값을 읽고 다음 다항식의 근을 출력하는 것을 반복 수행하는 프로그램을
 * 작성하여라.

    ax^2 + bx + c

 * 다음 방정식의 근은 실수가 될 수도 있고 복소수가 될 수도 있다.

    ax^2 + bx + c

 * a = 0이고 b = 0이면, 매우 잘못된(extreamly degenerate) 경우이다. 이 경우에는
 * 근을 구하지 않는다. a = 0이고 b != 0이면, 잘못된(degenerate) 경우이다. 이 경우,
 * 방정식은 다음과 같다.

    bx + c = 0

 * 그리고 이 방정식은 x = -c / b인 하나의 근만을 가진다. a != 0일 때(일반적인 경
 * 우), 근은 다음과 같이 계산된다.
 
    root_1 = {1 \over 2a}(-b + \sqrt(b^2 - 4ac))
    root_2 = {1 \over 2a}(-b - \sqrt{b^2 - 4ac})

 * 제곱근 기호 내의 식을 판별식이라고 한다. 판별식이 양수이면, 두 개의 실근(two
 * real roots)이 존재한다. 판별식이 0이면, 두 근은 실수이며 서로 같다. 이 경우에
 * 이 다항식은 실중근(multiple real roots)을 갖는다. 판별식이 음수이면, 두 근은
 * 복소수(two complex roots)이다. 각 a, b, c 값에 대해 근을 계산하고, 그 근을 다
 * 음 메시지 중 하나와 함께 출력하는 프로그램을 작성하여라.
 
    degenerate              two real roots
    extremely degenerate    two complex roots
    multiple real roots 

 * 예를 들어 a, b, c로 1, 2, 3이 입력되었다면, 다음과 같이 출력해야 한다.

    two complex roots: root1 = -1.000000 + i * 1.414214
                       root2 = -1.000000 - i * 1.414214

 */

#include <stdio.h>

int main(void)
{
    float a, b, c;
    float discriminant;
    float term1, term2;

    printf("Input values of a, b, c: ");
    scanf("%f%f%f", &a, &b, &c);

    if (a != 0){
        term1 = -(b / (2.0f * a));

        discriminant = pow(b, 2.0f) - (4.0f * a * c);
        term2 = sqrt(fabs(discriminant)) / (2.0f * a);

        if (discriminant < 0){
            printf("Two complex roots\n");
            printf("Root1: %f + i * %f\n", term1, term2);
            printf("Root2: %f - i * %f\n", term1, term2);
        }
        else if (discriminant == 0){
            printf("Multiple real roots\n");
            printf("Roots: %f\n", term1);
        }
        else{
            printf("Two real roots\n");
            printf("Root1: %f + %f\n", term1, term2);
            printf("Root2: %f - %f\n", term1, term2);
        }
    }
    else{
        if (b != 0){
            printf("Degenerate\n");
            printf("x = %f\n", -(c/b));
        }
        else{
            printf("Extremely degenerate\n");
        }
    }


    return 0;
}