#include <stdio.h>
#include <stdlib.h>
#include "list.h"

LINK string_to_list(char s[]);
void print_list(LINK head);
int count(LINK head);


int main(void)
{
    LINK h;

    h = string_to_list("ABC");
    printf("The resulting list is \n");
    print_list(h);
    printf("\nThis list has %d elements.\n", count(h));
    return 0;
}