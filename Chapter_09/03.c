/* Chapter 9 exercise 3 */

/* 연습문제 2번의 프로그램은 특정사항을 설명하기 위해서 새로운 블록을 사용하
 * 여 코드가 자연스럽지 않다. 이 연습 문제에서는 typedef를 다시 사용하고, 이번
 * 에는 코드가 매우 단순하다.

    typedef char * string;

    int main(void)
    {
        string a[] = {"I", "like", "to", "fight,"},
               b[] = {"pinch,", "and", "bite."};

        printf("%s %s %s %s %s %s %s\n",
            a[0], a[1], a[2], a[3], b[0], b[1], b[2]);
        return 0;
    }

 * 먼저 프로그램을 실행해 보아라. 이 프로그램에서 typedef를 다음으로 대치하여
 * 라.
 
    #define string char *

 * 이제 컴파일이 되지 않을 것이다. 왜 typedef를 사용하면 되고, #define을 사용
 * 하면 안 되는지 설명하여라. #define을 사용하려면, 한 문자를 더 추가해야 한다.
 * 어떤 문자인가?
 */

#include <stdio.h>

// typedef char * string;
#define string char *

int main(void)
{
    string  a[] = {"I", "like", "to", "fight,"},
            *b[] = {"pinch,", "and", "bite."};      // if use typedef, delete *

    printf("%s %s %s %s %s %s %s\n",
        a[0], a[1], a[2], a[3], b[0], b[1], b[2]);
    return 0;
}