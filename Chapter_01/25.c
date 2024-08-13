/* Chapter 1 exercise 25 */

/* 다음 프로그램에는 prn_string() 함수가 정의되어 있지 않다. 인자로 전달되는
 * 문자열을 출력하기 위해 putchar()를 사용하는 prn_string() 함수를 작성하여
 * 프로그램을 완성하여라. 문자열은 널 문자 \0으로 끝난다는 것을 기억하여라.
 * 이 프로그램은 표준 라이브러리에 있는 strcat() 함수를 사용한다. 이 함수의 원형은
 * string.h 헤더 파일에 있다. 이 함수는 두 개의 문자열을 인자로 가지며, 이
 * 두 문자열을 연결한 다음 그 결과를 첫 번째 인자에 넣는다.

    #include <stdio.h>
    #include <string.h>

    #define MAXSTRING 100

    void prn_string(char *);

    int main(void)
    {
        char s1[MAXSTRING], s2[MAXSTRING];
        strcpy(s1, "Mary, Mary, quite contrary, \n");
        strcpy(s2, "how does your garden grow?\n");
        prn_string(s1);
        prn_string(s2);
        strcat(s1, s2);     // concatenate the strings
        prn_string(s1);
        return 0;
    }

 */

#include <stdio.h>
#include <string.h>

#define MAXSTRING 100

void prn_string(char *);

int main(void)
{
    char s1[MAXSTRING], s2[MAXSTRING];
    strcpy(s1, "Mary, Mary, quite contrary, \n");
    strcpy(s2, "how does your garden grow?\n");
    prn_string(s1);
    prn_string(s2);
    strcat(s1, s2);     /* concatenate the strings */
    prn_string(s1);
    return 0;
}

void prn_string(char *s)
{
    while (*s != '\0'){
        putchar(*s);
        s++;
    }
}