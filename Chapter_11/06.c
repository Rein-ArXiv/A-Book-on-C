/* Chapter 11 exercise 6 */

/* 파일의 내용을 화면에 한 번에 20 줄씩 출력하는 프로그램을 작성하여라. 입력 파
 * 일명은 명령어 라인 인자로 주어져야 한다. 이 프로그램은 리턴키가 입력되면 20
 * 줄씩 출력되어야 한다. (이것은 UNIX의 more 유틸리티의 초보적인 형태이다.)
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE    1000
#define LINE_PER_SCREEN 20

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

void wait_enter()
{
    printf("Press Enter to view next 20 lines.\n");
    while(1)
    {
        int c = getchar();
        if (c == '\n')
        {
            break;
        }
    }
}

void clear_screen()
{
    system(CLEAR_COMMAND);
}

int main(int argc, char** argv)
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

    char line[MAX_LINE];
    int line_num = 0;

    while (fgets(line, sizeof(line), ifp))
    {
        puts(line);
        line_num++;
        
        if (line_num % LINE_PER_SCREEN == 0)
        {
            wait_enter();
            clear_screen();
        }
    }

    printf("\n------- FILE END --------\n");
    return 0;
}
