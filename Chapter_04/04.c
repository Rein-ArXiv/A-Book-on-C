/* Chapter 4 exercise 4 */

/* 한 파일에서 알파벳의 첫 세 문자(a, A, b, B, c, C)의 발생 횟수를 세는 프로그램
 * 을 작성하여라. 소문자와 대문자는 구별하지 않는다.
 */

#include <stdio.h>

int main(void)
{
	int a_count = 0, b_count = 0, c_count = 0;
    char c;
    while ((c = getchar()) != EOF){
        if (c == 'a' || c == 'A'){
            a_count++;
        }
        else if (c == 'b' || c == 'B'){
            b_count++;
        }
        else if (c == 'c' || c == 'C'){
            c_count++;
        }
    }

	printf("Count of A: %d\nCount of B: %d\nCount of C: %d\n", a_count, b_count, c_count);
	return 0;
}