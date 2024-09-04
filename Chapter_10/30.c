/* Chapter 10 exercise 30 */

/* int 형의 배열을 받아들여 이진 트리를 생성하는 함수를 작성하여라. 단 생성된
 * 이진트리의 모든 노드에 대해 부모 노드의 값은 왼쪽 자식 노드의 값보다는 커야
 * 하고, 오른쪽 자식 노드의 값보다는 크지 않아야 한다. 이러한 이진트리를 이진탐
 * 색 트리라고 한다. 다음은 이진탐색 트리의 예이다.

                    8
            4               15
        2       6       8       17

 * 이 이진트리에 새로운 원소를 삽입할 때에는 그 원소와 루트를 비교하여 작으면
 * 왼쪽 부트리에 삽입하고, 크거나 같으면 오른쪽 부트리에 삽입한다. 이러한 과정
 * 을 부트리가 NULL일 때까지 재귀적으로 반복 수행한다.
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

void inorder_traversal(BTREE root) {
    if (root != NULL) {
        inorder_traversal(root -> left);
        printf("%d ", root -> d);
        inorder_traversal(root -> right);
    }
}

int main() {
    DATA arr[] = {8, 4, 15, 2, 6, 17, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    BTREE root = array_to_bst(arr, size);

    printf("Inorder Traversal of the BST: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}