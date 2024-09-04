/* Chapter 10 exercise 32 */

/* 이진트리의 루트를 제거하고, 이 트리의 제일 오른쪽의 리프 노드를 루트로 만드
 * 는 프로그램을 작성하여라.

                                루트 노드의 삭제와 대처
                이전                                            이후
                
                a                                               f
        b               c                               b               c
    d       e       f                               d       e

 */

#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

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

BTREE insert_bst(BTREE root, DATA d) {
    if (root == NULL) {
        return create_node(d);
    }
    
    if (d < root -> d){
        root -> left = insert_bst(root -> left, d);
    }
    
    else {
        root -> right = insert_bst(root -> right, d);
    }

    return root;
}

BTREE array_to_bst(DATA arr[], int size) {
    BTREE root = NULL;

    for (int i = 0; i < size; i++) {
        root = insert_bst(root, arr[i]);
    }

    return root;
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

void store_inorder(BTREE root, DATA *key, int *index) 
{
    if (root != NULL) {
        store_inorder(root -> left, key, index);
        key[(*index)++] = root -> d;
        store_inorder(root -> right, key, index);
    }
}

DATA* bst_to_array(BTREE root, int size)
{
    DATA *key = (DATA*) malloc(size * sizeof(DATA));
    int index = 0;
    store_inorder(root, key, &index);
    return key;
}

void print_array(DATA arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

BTREE find_parent_of_rightmost_leaf(BTREE root) {
    if (root == NULL || (root->right == NULL && root->left == NULL)) {
        return NULL;  // 트리가 비어 있거나 루트가 유일한 노드일 때
    }

    BTREE parent = root;
    BTREE child;
    
    if (parent -> right != NULL){
        child = parent -> right;
    }
    else {
        child = parent -> left;
    }

    // 오른쪽 자식을 계속 내려감
    while (child != NULL && (child -> right != NULL || child -> left != NULL)) {
        parent = child;
        if (child -> right != NULL) {
            child = child -> right;
        }
        else{
            child = child -> left;
        }
    }

    return parent;
}

BTREE replace_root_with_rightmost_leaf(BTREE root) {
    if (root == NULL) {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    BTREE parent_of_rightmost = find_parent_of_rightmost_leaf(root);
    BTREE rightmost_leaf;

    if (parent_of_rightmost == root && root -> right != NULL) {
        rightmost_leaf = root -> right;
        parent_of_rightmost -> right = rightmost_leaf -> left;
    }
    else if (parent_of_rightmost -> right != NULL) {
        rightmost_leaf = parent_of_rightmost -> right;
        parent_of_rightmost -> right = NULL;
    }
    else {
        rightmost_leaf = parent_of_rightmost -> left;
        parent_of_rightmost -> left = NULL;
    }

    rightmost_leaf -> left = root -> left;
    rightmost_leaf -> right = root -> right;

    free(root);
    return rightmost_leaf;
}

void inorder_traversal(BTREE root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->d);
        inorder_traversal(root->right);
    }
}

int main() {
    DATA arr[] = {8, 4, 15, 2, 6, 17, 8};  // 입력 배열
    int size = sizeof(arr) / sizeof(arr[0]);

    // 이진 탐색 트리 생성
    BTREE root = NULL;
    for (int i = 0; i < size; i++) {
        root = insert_bst(root, arr[i]);
    }

    // 트리 출력 (중위 순회)
    printf("Original BST (Inorder Traversal): ");
    inorder_traversal(root);
    printf("\n");

    // 루트를 가장 오른쪽 리프 노드로 대체
    root = replace_root_with_rightmost_leaf(root);

    // 대체 후 트리 출력 (중위 순회)
    printf("After replacing root with rightmost leaf (Inorder Traversal): ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}