/* Chapter 4 exercise 31 */

/* goto를 사용하면 프로그램이 복잡해지기 때문에, 현대의 프로그램에서는 goto 문
 * 을 거의 사용하지 않는다. 다음 코드는 몇 개의 goto를 사용해도 제어의 흐름이
 * 복잡해진다는 것을 보인 것이다.
 
    d = b * b - 4.0 * a * c;
    if (d == 0.0) goto L1;
    else
        if (d > 0.0) {
            if (a != 0.0) {
                r1 = (-b + sqrt(d)) / (2.0 * a);
                r2 = (-b - sqrt(d)) / (2.0 * a);
                goto L4;
            }
            else
                goto L3;
        }
        else
            goto L2;
    L1: if (a != 0.0)
            r1 = r2 = -b / (2.0 * a);
        else
            goto L3;
    goto L4;
    L2: if (a != 0.0) {
            printf("imaginary roots\n");
            goto L4;
        }
    L3: printf("degenerate case\n");
    L4: .....

 * 이 프로그램을 보면 프로그래머가 다른 경우가 추가될 때마다 코드를 짜집기 해
 * 야되었고, 그에 따라 프로그램은 매우 불분명하게 된 것을 볼 수 있다. 이 코드를
 * goto 문이 없는 코드로 다시 작성하여라.
 */

#include <stdio.h>

int main(void)
{
    float a, b, c, d;
    float r1, r2;

    scanf("%f %f %f", &a, &b, &c);

    d = b * b - 4.0 * a * c;

    if (d == 0.0){
        if (a != 0.0)
            r1 = r2 = -b / (2.0 * a);
        else
            printf("degenerate case\n");
    }
    else
        if (d > 0.0) {
            if (a != 0.0) {
                r1 = (-b + sqrt(d)) / (2.0 * a);
                r2 = (-b - sqrt(d)) / (2.0 * a);
                printf("L4 start\n");
            }
            else
                printf("degenerate case\n");
        }
        else {
            if (a != 0.0) {
                printf("imaginary roots\n");
                printf("L4 start\n");
            }
        }

    return 0;
}