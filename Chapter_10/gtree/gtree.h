/* In file gtree.h */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

struct node {
    int child_no;
    DATA d;
    struct node *sib;
};

typedef struct node NODE;
typedef NODE *GTREE;

#include "fct_proto.h"  // function prototype
