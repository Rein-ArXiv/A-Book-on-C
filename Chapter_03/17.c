/* Chapter 3 exercise 17 */

/* 24시간 표현을 갖는 시계에서 0시는 밤 12시이고, 23시는 밤 11시이다. 이런 시계
 * 에서는 23에 1을 더하면 24가 아니라 0이다. 즉, 24는 존재하지 않는다. 마찬가지
 * 로 22에 5를 더하면, 3이 된다. 왜냐하면 22에 2를 더하면 0이 되고, 여기에 3을
 * 더하기 때문이다. 이러한 연산을 모듈러 연산, 더 정확히 표현하면 모듈러 24 연
 * 산이라고 한다. 대부분의 컴퓨터에서는 모든 정수적형에 대해 모듈러 연산을 수행
 * 한다. 이것은 unsigned 형으로 쉽게 설명할 수 있다. 다음 프로그램을 실행하고
 * 출력 값이 무엇인지를 설명하여라.

    #include <limits.h>     // for UINT_MAX
    #include <stdio.h>

    int main(void)
    {
        int i;
        unsigned u = UINT_MAX;  // typically 4294967295 or 65535

        for (i = 0; i < 10; ++i)
            printf("%u + %d = %u\n", u, i, u + i);
        for (i = 0; i < 10; ++i)
            printf("%u * %d = %u\n", u, i, u * i);
        return 0;
    }

 */

#include <limits.h>     /* for UINT_MAX */
#include <stdio.h>

int main(void)
{
    int i;
    unsigned u = UINT_MAX;  /* typically 4294967295 or 65535 */

    for (i = 0; i < 10; ++i)
        printf("%u + %d = %u\n", u, i, u + i);
    for (i = 0; i < 10; ++i)
        printf("%u * %d = %u\n", u, i, u * i);
    return 0;
}
