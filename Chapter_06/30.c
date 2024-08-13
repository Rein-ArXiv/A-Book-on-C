/* Chpater 6 exercise 30 */

/* 간단한 암호화 기법은 일대일로 알파벳 문자를 바꾸는 것이다. 이 기법은 52개의
 * 소문자와 대문자에 대한 번역 표를 가지고 수행할 수 있다. 이 기법을 사용하여
 * 문서를 암호화하는 프로그램을 작성하여라. 또한 암호화된 문서를 해독하는 프로
 * 그램도 작성해 보아라. 이것은 실제로 사용하는 암호화 기법은 아니다. 그 이유를
 * 알고 있는가? 관심이 있다면, 더 안전한 암호화 시스템을 배우고 프로그래밍을 해
 * 보아라. UNIX를 사용하고 있다면, crypt 온라인 메뉴얼에서 암호화에 관련된 정
 * 보를 얻을 수 있을 것이다.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main(void)
{
    char text[1000];
    char key[26] = "qwertyuiopasdfghjklzxcvbnm";
    int i = 0;

    while ((text[i] = getchar()) != EOF){
        if (isalpha(text[i])){
            if (islower(text[i]))
                text[i] = key[text[i] - 'a'];
            else{
                text[i] = toupper(key[tolower(text[i]) - 'a']);
            }
        }
        i++;
    }
    printf("Input End.\n\n");
    printf("%s\n", text);
    return 0;
}