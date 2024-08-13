/* Chapter 1 exercise 22 */

/* 1.8절의 nice_day 프로그램에서 사용한 아이디어를 이용하여 총 문자 개수를 계산하는
 * nletters 프로그램을 작성하여라. 프로그램을 수행할 때 재지정을 사용하여라.
 * infile이 문서 파일이라면, 다음과 같이 프로그램을 수행한다.

    nletters < infile

 * 또한 다음과 같이 출력되도록 하여라.

    Number of letters : 179

 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int letter_num = 0;
    char c;

    printf("Please type your post. Press 'Ctrl+Z' to end typing.\n");
    while((c=getchar()) != EOF){
        if (c >= 'A' && c <= 'z')
            letter_num++;
    }

    printf("Number of letters : %d\n", letter_num);

    return 0;
}