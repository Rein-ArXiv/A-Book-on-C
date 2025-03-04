/* Chapter 11 exercise 2 */

/* 11.5절의 dbl_space 프로그램을 -n 형식의 옵션을 명령어 라인에서 사용할 수 
 * 있도록 수정하여라. 여기서, n은 1, 2, 3 중 하나가 될 수 있다. 그리고 n이 1이면,
 * 보통 쓰기로 출력한다. 즉, 입력 파일의 연속된 두 개 이상의 개행문자는 출력 파
 * 일에 한 개 의 개행 문자로 출력되어야 한다. n이 2라면, 한 줄 띄어쓰기로 출력한
 * 다. 즉, 입력 파일의 연속된 한 개 이상의 개행 문자는 출력 파일에 반드시 두 개
 * 의 개행문자로 출력되어야 한다. n이 3이면, 출력 결과는 반드시 두 줄 띄어쓰기
 * 로 되어야 한다.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_file(FILE *, FILE *, int);
void prn_usage(char *);

int main(int argc, char **argv)
{
    FILE *ifp, *ofp;
    int mode;

    if (argc != 4)
    {
        prn_usage(argv[0]);
        exit(1);
    }

    if ((argv[1][0] != '-') || ((argv[1][1] < '1' ) || argv[1][1] > '3'))
    {
        prn_usage(argv[0]);
        exit(1);
    }

    mode = argv[1][1] - '0';

    ifp = fopen(argv[2], "r");      // open for reading

    if (ifp == NULL)
    {
        perror("Error opening input file");
        exit(1);
    }

    ofp = fopen(argv[3], "w");      // open for writing

    if (ofp == NULL)
    {
        perror("Error opening output file");
        fclose(ifp);
        exit(1);
    }
    
    process_file(ifp, ofp, mode);

    fclose(ifp);
    fclose(ofp);
    return 0;
}

void process_file(FILE *ifp, FILE *ofp, int mode)
{
    int c;
    
    while ((c = getc(ifp)) != EOF)
    {
        putc(c, ofp);

        if (c == '\n')
        {
            for (int i = 1; i < mode; i++)
            {
                putc('\n', ofp);    // found a newline - duplicate it
            }
        }
    }
}

void prn_usage(char *pgm_name)
{
    printf("\n%s%s%s\n\n%s%s\n\n",
        "Usage: ", pgm_name, " -[1|2|3] infile outfile",
        "The contents of infile will be [Single|Double|Triple] spaced ",
        "and written to outfile.");
}
