/* Chapter 10 exercise 39 */

/* (고급 수준) 연습 문제 38번에서 사용한 행렬의 표현 방법은 희소 행렬의 곱셈에
 * 도 사용될 수 있다. 비록 행렬의 합은 행 연결 리스트로만 가지고 수행될 수 있지
 * 만, 곱셈은 열 연결 리스트와 행 연결 리스트 모두를 사용해야 된다. 희소 행렬
 * 곱셈을 수행하는 프로그램을 작성하여라.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int row;
    int col;
    int value;
    struct Node* row_next;
    struct Node* col_next;
} Node;

typedef struct SparseMatrix
{
    Node** row_heads;
    Node** col_heads;
    int rows;
    int cols;
} SparseMatrix;

Node* create_node(int row, int col, int value)
{
    Node* new_node = (Node*) malloc(sizeof(Node));

    if (!new_node)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    new_node -> row = row;
    new_node -> col = col;
    new_node -> value = value;
    new_node -> row_next = NULL;
    new_node -> col_next = NULL;
    return new_node;
}

SparseMatrix* create_sparse_matrix(int rows, int cols)
{
    SparseMatrix* matrix = (SparseMatrix*) malloc(sizeof(SparseMatrix));

    if (!matrix)
    {
        printf("Memroy allocation failed.\n");
        exit(1);
    }

    matrix -> rows = rows;
    matrix -> cols = cols;

    matrix -> row_heads = (Node**) calloc(rows, sizeof(Node*));
    matrix -> col_heads = (Node**) calloc(cols, sizeof(Node*));

    if (!matrix -> row_heads || !matrix -> col_heads)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return matrix;
}

void insert_value(SparseMatrix* matrix, int row, int col, int value)
{
    
}