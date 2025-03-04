/* Chapter 11 exercise 1 */

/* 11.5절의 dbl_space 프로그램을 수정하여 입력 파일의 이름을 명령어 라인에서
 * 입력받고, stdout으로 출력되게 하여라. 이렇게 하면, 다음 명령은 infile을 한
 * 줄 띄어쓰기 하여, outfile에 출력하게 한다.

    dbl_sp infile > outfile

 * 이 프로그램은 파일 재지정을 하고 있으므로, prn_info()에서 printf(...) 보
 * 다는 fprintf(stderr, ...)를 호출해야 한다. 오류 메시지를 stdout에 출력하
 * 면, 이것은 재지정되어 화면에서 볼 수 없을 것이다. > 기호는 stdout에 출력되는
 * 모든 내용을 재지정하는 데 사용된다. 이것은 stderr에 출력되는 내용에 대해서
 * 는 영향을 주지 않는다. 오류 메시지를 stderr에 출력하는 프로글매과 stdout에
 * 출력하는 프로그램을 작성하여라. 이 프로그램들을 실행해보고 그 차이점을 이해
 * 하여라.
 */

#include <stdio.h>
#include <stdlib.h>

void double_space(FILE *, FILE *);
void prn_info(char *);

int main(int argc, char **argv)
{
    FILE *ifp, *ofp;

    if (argc != 2)
    {
        prn_info(argv[0]);
        exit(1);
    }

    ifp = fopen(argv[1], "r");      // open for reading

    if (ifp == NULL)
    {
        perror("Error opening input file");
        exit(1);
    }

    double_space(ifp, stdout);
    fclose(ifp);
    return 0;
}

void double_space(FILE *ifp, FILE *ofp)
{
    int c;
    
    while ((c = getc(ifp)) != EOF)
    {
        putc(c, ofp);

        if (c == '\n')
        {
            putc('\n', ofp);    // found a newline - duplicate it
        }
    }
}

void prn_info(char *pgm_name)
{
    fprintf(stderr, "\n%s%s%s\n\n%s%s\n\n",
        "Usage: ", pgm_name, " infile",
        "The contents of infile will be double-spaced",
        "and written to stdout.");
}
