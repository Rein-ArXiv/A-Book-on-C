/* In file lower_case.c */
/* Write only lowercase on the screen. */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSTRING   100

int main(void)
{
    char command[MAXSTRING]; 
    int c;
    FILE *ifp;

    ifp = tmpfile();

    if (ifp == NULL)
    {
        perror("tmpfile");
        return 1;
    }

    FILE *cmd_output = popen("dir", "r");

    if (cmd_output == NULL)
    {
        perror("popen");
        fclose(ifp);
        return 1;
    }

    while ((c = getc(cmd_output)) != EOF)
    {
        putc(c, ifp);
    }
    pclose(cmd_output);

    rewind(ifp);

    while ((c = getc(ifp)) != EOF)
    {
        putchar(tolower(c));
    }
    fclose(ifp);
    return 0;
}
