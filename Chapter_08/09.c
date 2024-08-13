/* Chapter 8 exercise 9 */

/* C는 문자 처리를 위해 좋은 언어라는 평가를 받고 있다. 부분적으로, 이러한 평가
 * 는 문자 처리에 있어서 함수보다 매크로가 많이 사용되기 때문이다. 프로그래머는
 * 매크로를 사용하면 실행 시간을 상당히 단축할 수 있다고 믿고 있다. 이것이 사실
 * 일까? 이 연습 문제는 이러한 것이 사실인지 검사하는 것이다. stdio.h와
 * ctype.h에 있는 매크로를 사용하는 프로그램을 먼저 작성해 보자.

    #include <ctype.h>
    #include <stdio.h>
    #include <time.h>

    int main(void)
    {
        int c;

        printf("Clock ticks: %ld\n", clock());  // start the clock
        while ((c = getchar()) != EOF)
            if (islower(c))
                putchar(toupper(c));
            else if (isupper(c))
                putchar(tolower(c));
            else if (isdigit(c))
                .....

 * 이 프로그램을 완성하여라. (A.15절에 있는 clock()을 참고하여라.) c가 숫자라
 * 면, 문자 x를 출력한다. c가 구두 문자라면, 아무 것도 출력하지 않는다. c가 공백
 * 문자라면, 이것을 두 번 출력한다. main() 함수의 return 문 바로 전에 다음 문
 * 장을 삽입하여라.
 
    printf("Clock ticks: %ld\n", clock());  // ticks up to now

 * 이제, 각 매크로를 대응하는 함수로 대치하여 프로그램을 작성하여라. 예를 들면,
 * islower(c) 대신 (islower)(c)를 사용하여라. 두 프로그램으로 문자 파일일을 처
 * 리하기 위해 재지정을 사용하여라. 파일이 작을 경우는 시스템의 오버헤드 때문에
 * 실행 시간에 큰 차이가 없을 것이다. 그러나 파일이 점점 커질수록, 실행 시간 차
 * 이가 생기게 된다. 사실인가? 힌트: 다음과 같이 하면 파일을 화면에 출력하는 시
 * 간을 낭비하지 않을 것이다.
 
    pgm < input > output

 */

#include <ctype.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    int c;


    // Macro, output1. 2 ticks

    printf("Clock ticks: %ld\n", clock());  // start the clock
    while ((c = getchar()) != EOF)
        if (islower(c))
            putchar(toupper(c));
        else if (isupper(c))
            putchar(tolower(c));
        else if (isdigit(c))
            putchar('x');
        else if (ispunct(c)){
            putchar(c);
            putchar(c);    
        }
    putchar('\n');
    printf("Clock ticks: %ld\n", clock());  // ticks up to now
    
    // Function, output2. 16 ticks

    /*
    printf("Clock ticks: %ld\n", clock());
        while ((c = getchar()) != EOF)
            if ((islower)(c))
                putchar((toupper)(c));
            else if ((isupper)(c))
                putchar((tolower)(c));
            else if ((isdigit)(c))
                putchar('x');
            else if ((ispunct)(c)) {
                putchar(c);
                putchar(c);
            }

    putchar('\n');
    printf("Clock ticks: %ld\n", clock());
    */

    return 0;
}

