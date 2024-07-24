/* In file insertion_list.c */

/* Intersting an element in a linked list. */

#include "list.h"

void insert(LINK p1, LINK p2, LINK q)
{
    assert(p1 -> next == p2);
    p1 -> next = q;     // insert
    q -> next = p2;
}