/* In file create.c */

#include "gtree.h"

// Create a new node.

GTREE new_gnode(void)
{
    return (malloc(sizeof(NODE)));
}

GTREE init_gnode(DATA d1, int num, GTREE sibs)
{
    GTREE temp;

    temp = new_gnode();
    temp -> d = d1;
    temp -> child_no = num;
    temp -> sib = sibs;
    return temp;
}

// Function buildtree creates a tree from an array of edges.

typedef struct { // PAIR represents an edge in a tree
    int out;
    int in;
} PAIR;

void buildtree(PAIR edges[], DATA d[], int n, GTREE t[])
{
    int i;
    int x, y;   // points of edge

    t[0] init_gnode(d[1], 1, NULL); // t[0] takes node 1 as root

    for (i = 1; i <= n; ++i)
        t[i] = NULL;
    for (i = 0; i < n - 1; ++i) {
        x = edges[i].out;
        y = edges[i].in;
        t[x] = init_gnode(d[y], y, t[x]);
    }
}
