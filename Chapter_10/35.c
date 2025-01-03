/* Chapter 10 exercise 35 */

/* 일반트리의 리프 노드의 최대 레벨을 계산하는 루틴을 작성하여라.
 */

#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

struct node
{
    DATA d;
    struct node *child;
    struct node *sibling;
};

typedef struct node NODE;
typedef NODE *GTREE;

GTREE create_node(DATA d)
{
    GTREE new_node = (GTREE) malloc(sizeof(NODE));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    new_node -> d = d;
    new_node -> child = NULL;
    new_node -> sibling = NULL;
    return new_node;
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