/* Chapter 4 exercise 28 */

/* 4.8절 "while 문"에서 공백, 숫자, 문자의 수를 세는 프로그램을 작성하였다. 이
 * 프로그램을 수정하여 소문자와 대문자를 구별하여 세도록 하여라.
 */

#include <stdio.h>

int main(void)
{
    int blank_cnt = 0, c, digit_cnt = 0, upper_cnt = 0, lower_cnt = 0, nl_cnt = 0, other_cnt = 0;

    while ((c = getchar()) != EOF)      // braces not necessary
        if (c == ' ')
            ++blank_cnt;
        else if (c >= '0' && c <= '9')
            ++digit_cnt;
        else if (c > 'a' && c <= 'z')
            ++lower_cnt;
        else if (c >= 'A' && c <= 'Z')
            ++upper_cnt;
        else if (c == '\n')
            ++nl_cnt;
        else
            ++other_cnt;
    
    printf("%12s%12s%12s%12s%12s%12s%12s\n\n",
        "blanks", "digits", "uppercases", "lowercases", "lines", "others", "total");
    printf("%12d%12d%12d%12d%12d%12d%12d\n\n",
        blank_cnt, digit_cnt, upper_cnt, lower_cnt, nl_cnt, other_cnt,
        blank_cnt + digit_cnt + upper_cnt + lower_cnt + nl_cnt + other_cnt);

    return 0;
}