/* In file list.h */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char DATA;

struct linked_list {
    DATA d;
    struct linked_list *next;
};

typedef struct linked_list ELEMENT;
typedef ELEMENT *LINK;

