/* Chapter 4 exercise 3 */

/* EOF를 만날 때까지 표준 입력 파일로부터 문자를 읽는 프로그램을 작성하여라. 숫
 * 자와 다른 문자의 개수를 세기 위해 digit_cnt와 other_cnt 변수를 사용하여라.
 */

#include <stdio.h>

int main(void)
{
    int digit_cnt = 0, other_cnt = 0;
    char c;
    while(scanf("%c", &c) != EOF){
        if (c >= '0' && c <= '9'){
            digit_cnt++;
        }
        else{
            other_cnt++;
        }
    }
    
    printf("Digit Count:%d\nOhter Count:%d\n", digit_cnt, other_cnt);

	return 0;
}