/* Chapter 6 exercise 39 */

/* 일반적으로 argc와 argv는 main() 함수의 인자로써 사용된다. argc는 명령어
 * 라인에서의 인자 수이기 때문에, 배열 argv의 크기를 argc라고 생각할 수도 있지
 * 만, 그렇지 않다. 배열 argv는 argc + 1의 크기를 갖고, 배열 마지막 원소는 널
 * 포인터이다. 다음은 echo 명령어의 다른 버전이다.

    #include <stdio.h>

    int main(int argc, char **argv)
    {
        while (*argv != NULL)
            printf("%s", *argv++);
        putchar('\n');
        return 0;
    }

 * 이 프로그램을 수행시켜보고, 이것을 이해하여라. 그리고 이 프로그램이 어떻게
 * 동작하는지 상세하게 기술하여라. 힌트: char 형 포인터에 대한 포인터가 역참조
 * 되면, 그 결과는 char 형 포인터가 된다. 또한 6.11절의 strcat() 함수 분석을
 * 다시 읽어 보아라.
 */

#include <stdio.h>

int main(int argc, char **argv)
{
    while (*argv != NULL)
        printf("%s", *argv++);
    putchar('\n');
    return 0;
}