/* Chapter 10 exercise 23 */

/* polish 프로그램을 검사할 때 사용한 폴리시 수식은 단항 연산자가 없었다. 다음
 * 수식으로 프로그램을 검사해 보아라.

    2, -3, -, -4, 7, +, -1, +, *

 * polish 프로그램이 정확히 동작하는가? 단항 +와 단항 - 연산자를 처리할 수 있
 * 도록 polish 프로그램을 다시 작성하여라. 예를 들어, 재작성된 프로그램은 다음
 * 과 같은 폴리시 수식을 처리할 수 있어야 한다.
 
    2, -, 3, -, -, 4, +, 7, +, -1, -, +, +, 1, +, *

 * 이 수식에서 어떤 +나 - 기호는 단항 연산자이고, 어떤 것은 이항 연산자이다.
 */

#include "polish/polish.h"

int evaluate(stack *polish) {
    data d, d1, d2;
    stack eval;
    initialize(&eval);

    while (!empty(polish)) {
        d = pop(polish);

        if (d.kind == value) {
            push(d, &eval);
        } else if (d.kind == operator) {
            if (empty(&eval)) {
                printf("Error: Invalid expression\n");
                exit(EXIT_FAILURE);
            }
            d1 = pop(&eval);
            if (d.u.op == '+' || d.u.op == '-') {
                if (empty(&eval)) {
                    // 단항 연산자로 처리
                    if (d.u.op == '-') {
                        d1.u.val = -d1.u.val;
                    }
                    push(d1, &eval);
                } else {
                    // 이항 연산자로 처리
                    d2 = pop(&eval);
                    if (d.u.op == '+') {
                        d1.u.val = d2.u.val + d1.u.val;
                    } else if (d.u.op == '-') {
                        d1.u.val = d2.u.val - d1.u.val;
                    }
                    push(d1, &eval);
                }
            } else {
                // 이항 연산자로만 사용 가능한 * 또는 /
                d2 = pop(&eval);
                if (d.u.op == '*') {
                    d1.u.val = d2.u.val * d1.u.val;
                } else if (d.u.op == '/') {
                    d1.u.val = d2.u.val / d1.u.val;
                }
                push(d1, &eval);
            }
        }
    }
    return pop(&eval).u.val;
}

void fill(stack *stk, const char *str) {
    const char *p = str;
    data d;
    stack tmp;
    initialize(stk);
    initialize(&tmp);

    while (*p != '\0') {
        while (isspace(*p) || *p == ',')
            p++;

        if (isdigit(*p) || ((*p == '-' || *p == '+') && isdigit(*(p + 1)))) {
            d.kind = value;
            sscanf(p, "%d", &d.u.val);
            while (isdigit(*p) || *p == '-' || *p == '+')
                p++;
        } else {
            d.kind = operator;
            d.u.op = *p++;
        }

        if (!full(&tmp))
            push(d, &tmp);
    }

    while (!empty(&tmp)) {
        d = pop(&tmp);
        if (!full(stk))
            push(d, stk);
    }
}

int main(void)
{
    stack polish_stack;
    initialize(&polish_stack);

    // 후위 표기식을 fill 함수로 스택에 채우기
    //fill(&polish_stack, "2, -3, -, -4, 7, +, -1, +, *");

    fill(&polish_stack, "2, 3, -, 4, -, 7, +, 1, -, +, 1, *, -");

    // 스택 내용을 출력하기 (디버깅용)
    printf("Stack contents before clearing:\n");
    prn_stack(&polish_stack);

    int result = evaluate(&polish_stack);
    printf("Result of the evaluation: %d\n", result);
    return 0;
}
