/* Chapter 6 exercise 40 */

/* C에서, 하나의 함수 원형은 여러 번 나올 수 있다. 더욱이 동등한 함수 원형은 서 
 * 로 충돌되지 않는다. 6.18절에서 제시한 find_roots 프로그램에는 다음 함수 원
 * 형이 있었다.
 
    dbl bisection(dbl f(dbl x), dbl a, dbl b);
 
 * 이것을 다음과 같은 함수 원형 목록으로 대치해 보아라.

    dbl bisection(pfdd, dbl, dbl);
    dbl bisection(pfdd f, dbl a, dbl b);
    dbl bisection(dbl (*)(dbl), dbl a, dbl b);
    dbl bisection(dbl (*f)(dbl), dbl a, dbl b);
    dbl bisection(dbl f(dbl), dbl a, dbl b);
    dbl bisection(dbl f(dbl x), dbl a, dbl b);

 * 컴파일할 때 문제가 발생하는가? (문제가 없어야 한다.)
 */

