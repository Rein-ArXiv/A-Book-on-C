/* Chapter 10 exercise 19 */

/* 10.6 절의 polish 프로그램을 사용하여 연습문제 17번과 18번의 6개의 폴리시 수
 * 식을 계산하여라.
 */


#include "polish/polish.h"

int precedence(char op)
{
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void convert_to_postfix(const char *infix, char *postfix)
{
    stack operators;
    initialize(&operators);

    const char *p = infix;
    char *q = postfix;
    data d;

    while (*p != '\0'){
        if (isspace(*p)){
            p++;
            continue;
        }
        
        if (isdigit(*p)){
            while (isdigit(*p)){
                *q++ = *p++;
            }
            *q++ = ' ';
        }
        else if (*p =='('){
            d.kind = operator;
            d.u.op = *p;
            push(d, &operators);
            p++;
        }
        else if (*p == ')'){
            while (!empty(&operators) && top(&operators).u.op != '('){
                *q++ = pop(&operators).u.op;
                *q++ = ' ';
            }
            pop(&operators);
            p++;
        } else if (*p == '+' || *p == '-' || *p == '*' || *p == '/'){
            while (!empty(&operators) && precedence(top(&operators).u.op) >= precedence(*p)){
                *q++ = pop(&operators).u.op;
                *q++ = ' ';
            }
            d.kind = operator;
            d.u.op = *p;
            push(d, &operators);
            p++;
        }
        else {
            printf("Invalid character encountered: %c\n", *p);
            return;
        }
    }

    while (!empty(&operators)){
        *q++ = pop(&operators).u.op;
        *q++ = ' ';
    }

    *(q - 1) = '\0';    // Null-terminator
}

int main(void)
{
    printf("Exercise 17:\n");

    char str1[] = "7, 6, -, 3, *";
    char str2[] = "9, 2, 3, *, 4, -, +";
    char str3[] = "1, 2, +, 3, 4, +, *";
    stack polish;
    
    printf("\n%s%s\n\n", "Polish expression: ", str1);
    fill(&polish, str1);         // fill stack from string
    prn_stack(&polish);
    printf("\n%s%d\n\n", "Polish evaluation: ", evaluate(&polish));

    printf("\n%s%s\n\n", "Polish expression: ", str2);
    fill(&polish, str2);         // fill stack from string
    prn_stack(&polish);
    printf("\n%s%d\n\n", "Polish evaluation: ", evaluate(&polish));
    
    printf("\n%s%s\n\n", "Polish expression: ", str3);
    fill(&polish, str3);         // fill stack from string
    prn_stack(&polish);
    printf("\n%s%d\n\n", "Polish evaluation: ", evaluate(&polish));
    putchar('\n');

    printf("Exercise 18:\n");
    
    const char infix_first[] = "(7 + 8 + 9) * 4";
    const char infix_second[] = "(6 - 2) * (5 + 15 * 2)";
    const char infix_third[] = "6 - 2 * 5 + 15 * 2";

    char postfix_first[FULL];
    char postfix_second[FULL];
    char postfix_third[FULL];

    convert_to_postfix(infix_first, postfix_first);
    convert_to_postfix(infix_second, postfix_second);
    convert_to_postfix(infix_third, postfix_third);

    printf("Infix: %s\n", infix_first);
    printf("Postfix: %s\n", postfix_first);

    printf("Infix: %s\n", infix_second);
    printf("Postfix: %s\n", postfix_second);

    printf("Infix: %s\n", infix_third);
    printf("Postfix: %s\n", postfix_third);

    return 0;
}