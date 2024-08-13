/* Chapter 5 exercise 6 */

/* 이번 연습 문제에서는 단정에 대하여 알아본다. 다음 프로그램을 수행하여 그 효
 * 과를 이해햐여라. 참고: 이것은 단정의 전형적인 사용 방법은 아니다.

    #include <assert.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    int main(void)
    {
        int a, b, cnt = 0, i;

        srand(time(NULL));
        for (i = 0;  i < 1000; ++i) {
            a = rand() % 3 + 1;     // from 1 to 3
            b = rand() % 30 + 1;    // from 1 to 30

            if (b - a <= 1)
                continue;
            assert(b - a > 2);
            printf("%3d\n", ++cnt);
        }
        return 0;
    }

 * a와 b가 어떤 값을 가졌을 때 단정이 실패하는가? 평균적으로, 이 루프는 몇 번
 * 수행되겠는가?
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int a, b, cnt = 0, i;

    srand(time(NULL));
    for (i = 0;  i < 1000; ++i) {
        a = rand() % 3 + 1;     // from 1 to 3
        b = rand() % 30 + 1;    // from 1 to 30

        if (b - a <= 1)         // 경우의 수 90개, b - a <= 1인 경우의 수 9개
            continue;
        assert(b - a > 2);      // 10% 확률로 실패
        printf("%3d\n", ++cnt);
    }
    return 0;
}