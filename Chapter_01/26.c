/* Chapter 1 exercise 26 */

/* 파일 재지정을 실험해 보자. 1.10절 "운영체제의 고찰"에서 dbl_out이라는 프로그램이
 * 있었다. 몇 줄의 문장으로 구성된 my_file이라는 파일을 만들어라. 재지정의 효과를
 * 이해하기 위해 다음 명령을 사용하여 프로그램을 실행시켜 보아라.
    
    dbl_out < my_file
    dbl_out < my_file > tmp
    
 * 다음 명령의 동작은 재미있다.

    dbl_out > tmp

 * 이 명령은 dbl_out이 키보드로부터 입력을 받아 그 결과를 tmp 파일에 쓰게 한다.
 * 물론 입력을 끝낼 때 파일의 끝을 알려주는 기호를 입력해야 한다. 캐리지 리턴 키
 * 다음에 control-d(in windows, control-z)를 입력하지 않고, 프로그램을 끝내는 control-c를 입력하면
 * 어떤 일이 발생하겠는가? tmp 파일에는 어떤 것이 출력되어 있겠는가?
 */

#include <stdio.h>

int main(void)
{
    char c;

    while (scanf("%c", &c) == 1){
        printf("%c", c);
        printf("%c", c);
    }
    return 0;
}