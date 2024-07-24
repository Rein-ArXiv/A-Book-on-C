/* In file concatenate_list.c */

#include "list.h"

void concatenate(LINK a, LINK b)
{
    assert(a != NULL);
    if (a -> next == NULL)
        a -> next = b;
    else
        concatenate(a -> next, b);
}