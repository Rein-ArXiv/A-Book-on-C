/* Chapter 4 exercise 27 */

/* 앞의 연습 문제에서 작성한 프로그램을 수정하여 중괄호와 괄호를 동시에 처리할
 * 수 있도록 하여라.
 */

#include <stdio.h>

int main(void)
{
    int left_brace_cnt = 0, right_brace_cnt = 0;
    int left_parenthesis_cnt = 0, right_parenthesis_cnt = 0;
    char c;

    while ((c = getchar()) != EOF){
        if (c == '{'){
            left_brace_cnt++;
        }
        if (c == '}'){
            right_brace_cnt++;
        }

        if (c == '('){
            left_parenthesis_cnt++;
        }
        if (c == ')'){
            right_parenthesis_cnt++;
        }
    }

    if (left_brace_cnt != right_brace_cnt){
        printf("ERROR : Missing ");
        
        if (left_brace_cnt > right_brace_cnt){
            printf("right braces : ");
            while (left_brace_cnt != right_brace_cnt){
                putchar('}');
                right_brace_cnt++;
            }
        }
        else if(right_brace_cnt > left_brace_cnt){
            printf("left braces : ");
            while (left_brace_cnt != right_brace_cnt){
                putchar('{');
                left_brace_cnt++;
            }
        }
    printf("\n");
    }

    if (left_parenthesis_cnt != right_parenthesis_cnt){
        printf("ERROR : Missing ");
        
        if (left_parenthesis_cnt > right_parenthesis_cnt){
            printf("right parentheses : ");
            while (left_parenthesis_cnt != right_parenthesis_cnt){
                putchar(')');
                right_parenthesis_cnt++;
            }
        }
        else if(right_parenthesis_cnt > left_parenthesis_cnt){
            printf("left parentheses : ");
            while (left_parenthesis_cnt != right_parenthesis_cnt){
                putchar('(');
                left_parenthesis_cnt++;
            }
        }
    printf("\n");
    }    

    printf("Read end\n");
    return 0;
}