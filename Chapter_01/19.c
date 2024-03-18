/* Chapter 1 exercise 19 */

/* 다음 코드를 포함하는 프로그램을 작성한 후 수행시켜 보아라.
 
    int a1, a2, a3, cnt;

    printf("Input three integers : ");
    cnt = scanf("%d%d%d", &a1, &a2, &a3);
    printf("Number of successful conversion : %d\n", cnt);

 * 프로그램이 입력을 기다릴 때 문자 x를 입력하면 어떻게 되겠는가?
 * 어떤 숫자가 출력될 수 있겠는가? 힌트: scanf()가 변환을 수행하기 전에 파일의 끝을 만나면
 * EOF 값이 리턴된다. EOF는 stdio.h에 정의된 기호 상수로서 일반적으로 그 값은 -1이다.
 */

#include <stdio.h>

int main(void)
{
    int a1, a2, a3, cnt;

    printf("Input three integers : ");
    cnt = scanf("%d%d%d", &a1, &a2, &a3);
    printf("Number of successful conversion : %d\n", cnt);

    return 0;
}