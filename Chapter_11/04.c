/* Chapter 11 exercise 4 */

/* 파일에 행 번호를 매기는 프로그램을 작성하여라. 입력 파일명은 명령어 라인 인
 * 자로 전달되어야 한다. 프로그램은 stdout에 출력해야 한다. 입력 파일의 각 행
 * 의 앞에는 행 번호와 공간이 하나 붙어서 출력 파일에 출력되게 하여라.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *ifp = fopen(argv[1], "r");

    if (ifp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char line[1000];
    int line_num = 1;

    while (fgets(line, sizeof(line), ifp))
    {
        printf("%3d %s", line_num++, line);
    }
    putchar('\n');

    fclose(ifp);
    return 0;
}