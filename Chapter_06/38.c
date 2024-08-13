/* Chapter 6 exercise 38 */

/* 다음 코드는 문자열에 있는 문자를 역순으로 만들기 위하여 사용될 수 있다.
 
    char *reverse(char *s)
    {
        char *p, *q, tmp;
        int n;

        n = strlen(s);
        q = (n > 0) ? s + n - 1 : s;
        for (p = s; p < q; ++p, --q) {
            tmp = *p;
            *p = *q;
            *q = tmp;
        }
        return s;
    }

 * 다음 문장들을 포함하는 프로그램을 작성하여 이 함수를 검사해 보아라.

    char str[] = "abcdefghijklnopqrstuvwxzy";

    printf("%s\n", reverse(str));

 * 작성한 프로그램을 실행하여 이것을 이해하여라. 다음 그림은 for 루프의 시작
 * 지점에서의 메모리 내용을 보여주고 있다.
 
    p -> a | b | c | d | e | f | ... | x | y | q -> z | \0

 * 왜 이 그림이 옳은지를 설명하여라. for 루프의 각 반복 후의 메모리 상태를 유
 * 사한 그림으로 차례로 그려보아라.
 */

#include <stdio.h>
#include <string.h>

char *reverse(char *s)
{
    char *p, *q, tmp;
    int n;

    n = strlen(s);
    q = (n > 0) ? s + n - 1 : s;
    for (p = s; p < q; ++p, --q) {
        tmp = *p;
        *p = *q;
        *q = tmp;
    }
    return s;
}

int main(void)
{
    char str[] = "abcdefghijklnopqrstuvwxzy";

    printf("%s\n", reverse(str));
    return 0;
}