/* Chapter 10 exercise 22 */

/* 폴리시 스택의 내용을 사용자가 직접 초기화시킬 수 있게 하는 루틴을 작성하여
 * 라. 그리고 그 루틴을 검사하는 프로그램을 작성하여 검사해 보아라.
 */

#include "polish/polish.h"

void clear(stack *stk)
{
    while (!empty(stk)) {
        pop(stk);  // 스택의 모든 요소를 제거
    }
    stk->cnt = 0;    // 스택 카운터를 초기화
    stk->top = NULL; // 스택의 top을 초기화
}

int main(void)
{
    stack polish_stack;
    initialize(&polish_stack);

    // 후위 표기식을 fill 함수로 스택에 채우기
    fill(&polish_stack, "3, 4, +, 2, *, 7, /");

    // 스택 내용을 출력하기 (디버깅용)
    printf("Stack contents before clearing:\n");
    prn_stack(&polish_stack);

    // 스택 초기화 (Clear the stack)
    clear(&polish_stack);

    // 스택이 비워졌는지 확인하기
    printf("Stack contents after clearing:\n");
    prn_stack(&polish_stack);

    return 0;
}
