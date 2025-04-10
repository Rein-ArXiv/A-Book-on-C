/* Chapter 11 exercise 5 */

/* A.12절에서 ungetc() 함수에 대한 내용을 읽어보아라. 파일에서 세 개의 문자를
 * 읽어들인 후, ungetc() 함수를 이용하여 이 파일에 세 개의 문자를 다시 집어넣
 * 을 수 있는가? 이것을 검사할 수 있는 프로그램을 작성하여라.
 */

// int ungetc(int c, FILE *fp)

#include <stdio.h>

int main()
{
    FILE *fp = fopen("input.txt", "r");

    if (!fp)
    {
        perror("File open failed");
        return 1;
    }

    int c1 = getc(fp);
    int c2 = getc(fp);
    int c3 = getc(fp);

    printf("Read: %c %c %c\n", c1, c2, c3);

    ungetc(c3, fp);
    ungetc(c2, fp);
    ungetc(c1, fp);

    int r1 = getc(fp);
    int r2 = getc(fp);
    int r3 = getc(fp);
    printf("Pushed back: %c %c %c\n", r1, r2, r3);

    // printf("Pushed back: %c %c %c\n", getc(fp), getc(fp), getc(fp)); // Compiler에 따라 다른 결과 나타날 수 있음

    fclose(fp);
    return 0;
}