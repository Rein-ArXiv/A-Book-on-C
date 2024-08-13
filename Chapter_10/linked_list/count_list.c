/* In file count_list.c */
/* Count a list recursively. */

#include "list.h"

int count(LINK head)
{
    if (head == NULL)
        return 0;
    else
        return 1 + count(head -> next);
}

/* Count a list iteratively. */

int count_it(LINK head)
{
    int cnt = 0;

    for (; head != NULL; head = head -> next)
        ++cnt;
    return cnt;
}