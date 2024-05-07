/* Chapter 6 exercise 12 */

/* n차 이하의 실수 다항식 p(x)는 다음과 같다.
 * 의미를 설명하여라.

    p(x) = a_0 + a_1 x + a_2 x^2 + ... + a_n x^n

 * 여기서 계수 a_0, a_1, ..., a_n은 실수이다. 만일 a_n != 0이면,
 * p(x)의 차수는 n이다. 다항식은 다음과 같은 배열로 컴퓨터에서 표현될 수 있다.

    #define     N   5       // N is the max degree

    double p[N + 1];

 * 주어진 x에 대한 다항식 p의 값을 리턴하는 다음 함수를 작성해 보아라.

    double eval(double p[], double x, int n) // n is max degree
    {
        
 * 두 가지 버전의 함수를 작성하여라. 첫 번째 버전은 직관적인 방법을 사용하여 값
 * 을 계산해야 한다. 두 번째 버전은 Horner의 법칙을 사용해야 한다. Horner의 법
 * 칙은 5차 다항식을 다음과 같이 기술한다.
 
    p(x) = a_0 + x(a_1 + x(a_2 + x(a_3 + x(a_4 + x(a_5)))))

 * eval() 함수의 두 가지 버전에서 덧셈과 곱셉의 수는 각각 얼마나 되는가?
 */
