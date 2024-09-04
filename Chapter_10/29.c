/* Chapter 10 exercise 29 */

/* 이진트리에서 다음과 같은 일을 수행하는 루틴을 작성하여라.

    1. 노드의 수를 센다.
    2. 특정한 값을 갖는 노드의 수를 센다.
    3. 리프 노드의 값만 출력한다.

 */

#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

struct node {
    DATA d;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;
typedef NODE *BTREE;

BTREE create_node(DATA d) {
    BTREE new_node = (BTREE) malloc(sizeof(NODE));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    new_node -> d = d;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

int count_nodes(BTREE root)
{
    if (root == NULL){
        return 0;
    }
    else {
        return 1 + count_nodes(root -> left) + count_nodes(root -> right);
    }
}

int count_value_nodes(BTREE root, DATA value)
{
    if (root == NULL){
        return 0;
    }
    else {
        return (value == root -> d) + count_value_nodes(root -> left, value) + count_value_nodes(root -> right, value);
    }
}

void print_leaf_nodes(BTREE root) {
    if (root == NULL)
        return;
    
    if (root->left == NULL && root->right == NULL) {
        printf("%c ", root -> d);
        return;
    }
    
    print_leaf_nodes(root -> left);
    print_leaf_nodes(root -> right);
}

int main() {
    BTREE root = create_node('A');
    root -> left = create_node('B');
    root -> right = create_node('C');
    root -> left -> left = create_node('D');
    root -> left -> right = create_node('E');
    root -> right -> right = create_node('F');

    printf("Total number of nodes: %d\n", count_nodes(root));
    printf("Number of nodes with value 'B': %d\n", count_value_nodes(root, 'B'));
    printf("Leaf nodes: ");
    print_leaf_nodes(root);
    printf("\n");

    return 0;
}