/* Chapter 4 exercise 26 */

/* 중괄호 쌍이 올바로 사용되었는지 조사하는 프로그램을 작성하여라. 프로그램에서
 * 다음 두 개의 변수를 사용해야 한다: 왼쪽 중괄호를 조사하는 left_cnt 변수와
 * 오른쪽 중괄호를 조사하는 right_cnt 변수. 각각의 변수는 0으로 초기화되어야
 * 한다. 프로그램은 입력 파일에서 각 문자를 읽고 출력할 수 있어야 한다. 중괄호
 * 를 만나면 해당 변수를 증가시킨다. 만일 right_cnt 값이 left_cnt 값을 초과
 * 하면 그 지점에서 문자쌍 ??을 출력한다. 입력 파일의 모든 문자가 처리된 후에
 * left_cnt와 right_cnt의 값은 같아야 한다. 그렇지 않고 left_cnt 값이
 * right_cnt 값보다 크다면, 이에 대한 메시지와 부족한 개수만큼의 오른쪽 중괄
 * 호를 출력한다. 예를 들어, 다음과 같이 출력한다.
 
    ERROR : Missing right braces : }}}
  
 * 입출력을 위해 getchar()와 putchar() 매크로를 사용하여라. 이 프로그램의 입
 * 력 파일로 임의의 C 프로그램 파일을 사용하고, 이 프로그램을 수행해 보아라.
 */

#include <stdio.h>

int main(void)
{
    int left_cnt = 0, right_cnt = 0;
    char c;

    while ((c = getchar()) != EOF){
        if (c == '{'){
            left_cnt++;
        }
        if (c == '}'){
            right_cnt++;
        }
    }

    if (left_cnt != right_cnt){
        printf("ERROR : Missing ");
        
        if (left_cnt > right_cnt){
            printf("right braces : ");
            while (left_cnt != right_cnt){
                putchar('}');
                right_cnt++;
            }
        }
        else if(right_cnt > left_cnt){
            printf("left braces : ");
            while (left_cnt != right_cnt){
                putchar('{');
                left_cnt++;
            }
        }
    printf("\n");
    }    
    printf("Read end\n");
    return 0;
}