/* Chapter 8 exercise 19 */

/* 헤더 파일 stddef.h에서 size_t에 대한 typedef를 찾아보아라. 또한 stdlib.h
 * 에서도 이 typedef를 찾아보아라. 다음과 같은 행으로 시작되는 프로그램을 작성
 * 한다고 가정해 보자.

    #include <stddef.h>
    #include <stdlib.h>
     
 * 중복된 형 정의는 허용하지 않기 때문에, size_t에 대한 typedef이 두 번씩 포
 * 함되지 못하게 할 수 있어야 한다. 이것이 어떻게 수행되는지 설명하여라.
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    size_t size = sizeof(int);
    printf("Size of int: %zu bytes\n", size);

    return 0;
}