#include "gtree.h"

// Preorder traversal of general trees.

void preorder_g(GTREE t, int ind)
{
    GTREE tmp;      // tmp traverses the sibling list

    tmp = t[ind];   // t[ind] is the root node
    while (tmp != NULL) {
        printf("%c %d\n", tmp -> d, tmp -> child_no);
        preorder_g(t, tmp -> child_no);
        tmp = tmp -> sib;
    }
}
