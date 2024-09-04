/* Chapter 10 exercise 31 */

/* 연습 문제 30번에서 작성된 트리를 받아들여 배열에 저장하는 함수를 작성하여라.
 * 이 함수는 트리를 중위순회 방문하여 방문한 순서대로 key[] 배열에 저장해야 한
 * 다. 이렇게 수행하면 key[] 배열은 정렬된 값을 가질 것이다.
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

int main() {
    DATA arr[] = {8, 4, 15, 2, 6, 17, 8}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    BTREE root = array_to_bst(arr, size);

    int tree_size = count_nodes(root);

    DATA *sorted_array = bst_to_array(root, tree_size);

    printf("Inorder Traversal (sorted) of the BST: ");
    print_array(sorted_array, tree_size);

    free(sorted_array);

    return 0;
}