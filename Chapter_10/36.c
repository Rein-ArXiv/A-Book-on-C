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
        return root;
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
    if (root == NULL)
    {
        printf("Binary Tree is NULL.\n");
        return NULL;
    }

    GTREE gnode = create_gnode(root -> d);


    if (root -> left != NULL)
    {
        gnode -> child = btree_to_gtree(root -> left);
    }

    if (root -> right != NULL)
    {
        gnode -> sibling = btree_to_gtree(root -> right);
    }

    return gnode;
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

void print_gtree(GTREE root, int level)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < level; i++)
    {
        printf("..");
    }
    printf("%d\n", root -> d);

    print_gtree(root -> child, level + 1);
    print_gtree(root -> sibling, level);
}

int main()
{
    // 이진 트리 생성
    BTREE btree = NULL;
    btree = insert_bnode(10, btree);
    btree = insert_bnode(5, btree);
    btree = insert_bnode(15, btree);
    btree = insert_bnode(3, btree);
    btree = insert_bnode(7, btree);
    btree = insert_bnode(12, btree);
    btree = insert_bnode(18, btree);

    // 이진 트리를 일반 트리로 변환
    GTREE gtree = btree_to_gtree(btree);

    // 일반 트리 출력
    printf("General Tree Representation:\n");
    print_gtree(gtree, 0);

    return 0;
}