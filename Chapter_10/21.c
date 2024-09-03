/* Chapter 10 exercise 21 */

/* 새로운 polish 프로그램을 작성하여라. 먼저, 스택에 있는 원소들의 순서를 반대
 * 로 만드는 루틴을 작성하여라. 그 다음 stack.c 파일에 이 루틴을 추가하고 해당
 * 파일에 이 함수에 대한 원형을 첨가하여라. 그 다음 fill() 함수를 수정하여 새
 * 로 작성한 루틴을 사용하도록 하여라. 마지막으로 프로그램을 검사해 보아라.
 */

#include "polish/polish.h"

void initialize(stack *stk)
{
    stk -> cnt = 0;
    stk -> top = NULL;
}

void push(data d, stack *stk)
{
    elem *p;

    p = malloc(sizeof(elem));
    p -> d = d;
    p -> next = stk -> top;
    stk -> top = p;
    stk -> cnt++;
}

data pop(stack *stk)
{
    data d;
    elem *p;

    d = stk -> top -> d;
    p = stk -> top;

    stk -> top = p -> next;
    stk -> cnt--;
    
    free(p);
    return d;
}

data top(stack *stk)
{
    return stk -> top -> d;
}

boolean empty(const stack *stk)
{
    return ((boolean) (stk -> cnt == EMPTY));
}

boolean full(const stack *stk)
{
    return ((boolean) (stk -> cnt == FULL));
}

void reverse_stack(stack *stk) {
    stack tmp1, tmp2;
    initialize(&tmp1);
    initialize(&tmp2);

    while (!empty(stk)) {
        push(pop(stk), &tmp1);
    }

    while (!empty(&tmp1)) {
        push(pop(&tmp1), &tmp2);
    }

    while (!empty(&tmp2)) {
        push(pop(&tmp2), stk);
    }
}

void fill(stack *stk, const char *str) {
    const char *p = str;
    char c1, c2;
    boolean b1, b2;
    data d;

    initialize(stk);

    // First process the string and push data on tmp.
    while (*p != '\0') {
        while (isspace(*p) || *p == ',')
            ++p;
        b1 = (boolean) ((c1 = *p) == '+' || c1 == '-' || c1 == '*' || c1 == '/');
        b2 = (boolean) ((c2 = *(p + 1)) == ',' || c2 == '\0');

        if (b1 && b2) {
            d.kind = operator;
            d.u.op = c1;
        } else {
            d.kind = value;
            assert(sscanf(p, "%d", &d.u.val) == 1);
        }

        if (!full(stk))
            push(d, stk);
        while (*p != ',' && *p != '\0')
            ++p;
    }

    // Now reverse the stack tmp before pushing onto stk
    reverse_stack(stk);
}

int main(void)
{
    stack polish_stack;
    initialize(&polish_stack);

    // 후위 표기식을 fill 함수로 스택에 채우기
    fill(&polish_stack, "3, 4, +, 2, *, 7, /");

    // 스택 내용을 출력하기 (디버깅용)
    printf("Stack contents after filling:\n");
    prn_stack(&polish_stack);

    // 후위 표기식 계산 결과 출력하기
    int result = evaluate(&polish_stack);
    printf("Result of the evaluation: %d\n", result);

    return 0;
}
