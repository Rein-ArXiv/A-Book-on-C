/* Chapter 6 exercise 34 */

/* 6.14절의 my_echo 프로그램을 수정하여 -c 옵션을 사용할 경우 프로그램의 인자
 * 를 대문자로 출력하게 하여라. 단 이 옵션을 포함하는 인자는 출력하면 안 된다.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(int argc, char * argv[])
{
    int i;
    int uppercase = 0;

    for(i = 0; i < argc; ++i){
        if (strcmp(argv[i], "-c") == 0){
            uppercase = 1;
            break;
        }
    }

    printf("argc = %d\n", argc);
    for (i = 0; i < argc; ++i){
        if (strcmp(argv[i], "-c") == 0){
            continue;
        }

        printf("argc[%d] = ", i);

        if (uppercase){
            for (int j = 0; argv[i][j] != 0; ++j){
                printf("%c", toupper(argv[i][j]));
            }
            printf("\n");
        }
        else {
            printf("%s\n", argv[i]);
        }
    }
}