/* Chapter 8 exercise 13 */

/* 문자열화 연산자 #은 매크로로 전달되는 인자를 큰따옴표로 묶는다. 이때 인자가
 * 이미 큰따음표로 묶여 있다면 어떻게 될까?
 
    #define    YANK(x)    s = #x

    char *s;

    YANK("Go home, Yankee!");
    printf("%s\n", s)

 * # 연산자를 포함하지 않는 또 다른 버전의 프로그램을 작성하여라. 이 두 버전의
 * 프로그램을 실행해 보아라. 두 출력이 같은가? -E 옵션을 사용하여 전처리기에
 * 의해 확장된 코드를 확인해 보아라. # 연산자가 있을 때 전처리기는 어떻게 다르
 * 게 동작하는가?
 */

#include <stdio.h>

#define    YANK(x)    s1 = #x
#define    YANK_ALT(x)    s2 = x

int main(void){
    char *s;

    YANK("Go home, Yankee!");           // s1 = "\"Go home, Yankee!\"";
    YANK_ALT("Go home, Yankee!");       // s2 = "Go home, Yankee!";

    printf("%s\n", s1);
    printf("%s\n", s2);

    return 0;
}