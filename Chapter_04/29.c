/* Chapter 4 exercise 29 */

/* 다음 코드를 break나 continue 문을 사용하지 않는 코드로 수정하여라.
 
    while (c = getchar()) {
        if (c == 'E')
            break;
        ++cnt;
        if (c >= '0' && c <= '9')
            ++digit_cnt;
        }   
        i = -5;
        n = 50;
        while (i < n) {
            ++i;
            if (i == 0)
                continue;
            total += i;
            printf("i = %d and total = %d\n", i, total);
        }

 */

#include <stdio.h>

int main(void)
{
    char c;
    int cnt = 0, digit_cnt = 0;
    int i, n, total = 0;

    while ((c = getchar()) != 'E') {
        ++cnt;
        if (c >= '0' && c <= '9')
            ++digit_cnt;
        }   
    i = -5;
    n = 50;
    while (i < n) {
        ++i;
        if (i != 0){
            total += i;
            printf("i = %d and total = %d\n", i, total);
        }
    }
    return 0;
}
