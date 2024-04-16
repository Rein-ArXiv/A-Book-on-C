/* Chapter 4 exercise 23 */

/* 다음과 같은 x에 대한 2차 다항식을 보자.

   ax^2 + bx + c

 * 이 식의 판별식은 다음과 같다.

   b^2 - 4ac

 * 우리는 이 판별식의 제곱근에 관심이 있다. 만일 판별식이 음수가 아니라면, 다음
 * 식은 보통과 같이 해석된다.

   sqrt(b^2 - 4ac)


 * 그러나, 판별식이 음수이면, 위 식은 다음 식과 같은 의미이다.

   i sqrt(-(b^2-4ac))

 * 여기에서 i = sqrt(-1), 즉 i^2 = -1 이다.

 * 변수 a, b, c의 값을 읽어, 판별식의 제곱근을 출력하는 프로그램을 작성하여라.
 * 예를 들어 1, 2, 3이 입력되면, i * 2.828427이 출력되어야 한다.
 */

#include <stdio.h>

int main(void)
{
      float a, b, c;
      float discriminant;

      printf("Input values of a, b, c: ");
      scanf("%f%f%f", &a, &b, &c);

      discriminant = pow(b, 2.0f) - 4 * a * c;
      
      if (discriminant < 0){
         printf("i * ");
      }

      printf("%lf\n", sqrt(fabs(discriminant)));
      return 0;
}