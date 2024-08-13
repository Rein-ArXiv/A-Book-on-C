/* In file print_list.c */

#include <stdlib.h>
#include "list.h"

void print_list(LINK head)
{
    if (head == NULL)
        printf("NULL\n");
    else {
        printf("%c --> ", head -> d);
        print_list(head -> next);
    }
}