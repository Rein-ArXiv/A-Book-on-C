/* Chapter 10 exercise 36 */

/* 이진트리를 일반트리 표현으로 변환하는 함수를 작성하여라. 
 */

#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

struct binary_node {
    DATA d;
    struct binary_node *left;
    struct binary_node *right;
};

typedef struct binary_node BNODE;
typedef BNODE *BTREE;

struct general_node
{
    DATA d;
    struct general_node *child;
    struct general_node *sibling;
};

typedef struct general_node GNODE;
typedef GNODE *GTREE;

BTREE create_bnode(DATA d)
{
    BTREE new_node = (BTREE) malloc(sizeof(BNODE));

    if (new_node == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }

    new_node -> d = d;
    new_node -> left = NULL;
    new_node -> right = NULL;

    return new_node;
}

BTREE insert_bnode(DATA d, BTREE root)
{
    if (root == NULL)
    {
        root = create_bnode(d);
        return;
    }

    if (d < root -> d){
        root -> left = insert_bnode(d, root -> left);
    }

    else{
        root -> right = insert_bnode(d, root -> right);
    }
    return root;
}


GTREE create_gnode(DATA d)
{
    GTREE new_node = (GTREE) malloc(sizeof(GNODE));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    new_node -> d = d;
    new_node -> child = NULL;
    new_node -> sibling = NULL;
}

GTREE btree_to_gtree(BTREE root)
{

}

int max_leaf_level(GTREE node, int level)
{
    if (node == NULL)
    {
        return 0;
    }

    if (node -> child == NULL)
    {
        return level;
    }

    int max_level = 0;
    GTREE child = node -> child;
    while (child != NULL)
    {
        int leaf_level = max_leaf_level(child, level + 1);
        if (leaf_level > max_level)
        {
            max_level = leaf_level;
        }
        child = child -> sibling;
    }

    return max_level;
}


int main()
{
    // 샘플 트리 구성
    GTREE root = create_node(1);
    root->child = create_node(2);
    root->child->sibling = create_node(3);
    root->child->child = create_node(4);
    root->child->child->sibling = create_node(5);
    root->child->sibling->child = create_node(6);

    int max_level = max_leaf_level(root, 1);
    printf("Maximum level of leaf node: %d\n", max_level);

    return 0;
}