/* In file iter_list.c */

#include <stdlib.h>
#include "list.h"

/* List Creation using recursion. */

LINK string_to_list(char s[])
{
    LINK head;      // base case

    if (s[0] == '\0')
        return NULL;
    else{
        head = malloc(sizeof(ELEMENT));
        head -> d = s[0];
        head -> next = string_to_list(s + 1);
        return head;
    }
}

/* List Creation using iteration. */

LINK s_to_l(char s[])
{
    LINK head = NULL, tail;

    int i;

    if (s[0] != '\0') {             // first element
        head = malloc(sizeof(ELEMENT));
        head -> d = s[0];
        tail = head;

        for (i = 1; s[i] != '\0'; i++) {
            tail -> next = malloc(sizeof(ELEMENT));
            tail = tail -> next;
            tail -> d = s[i];
        }

        tail -> next = NULL;
    }
    return head;
}