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
    if (value == 0) return;

    Node* current = matrix -> row_heads[row];
    Node* prev = NULL;

    while (current && current -> col < col)
    {
        prev = current;
        current = current -> row_next;
    }

    if (current && current -> col == col)
    {
        current -> value = value;
        return;
    }

    Node* new_node = create_node(row, col, value);

    new_node -> row_next = current;

    if (prev)
    {
        prev -> row_next = new_node;
    }
    else
    {
        matrix -> row_heads[row] = new_node;
    }

    current = matrix -> col_heads[col];
    prev = NULL;

    while (current && current -> row < row)
    {
        prev = current;
        current = current -> col_next;
    }

    new_node -> col_next = current;

    if (prev)
    {
        prev -> col_next = new_node;
    }
    else
    {
        matrix -> col_heads[col] = new_node;
    }
}

SparseMatrix* multi_sparse_matrices(SparseMatrix* A, SparseMatrix* B)
{
    if ((A -> cols) != (B -> rows))
    {
        printf("Matrices cannot multiply.\n");
        return NULL;
    }

    int rows = A -> rows;
    int cols = B -> cols;

    SparseMatrix* result_matrix = create_sparse_matrix(rows, cols);

    for (int r = 0; r < A -> rows; r++)
    {
        for (int c = 0; c < B -> cols; c++)
        {
            Node* current_A_node = A -> row_heads[r];
            Node* current_B_node = B -> col_heads[c];

            if (!current_A_node)
            {
                break;
            }
            if (!current_B_node)
            {
                continue;
            }

            int multiple_element = 0;

            while (current_A_node && current_B_node)
            {
                if (current_A_node -> col < current_B_node -> row)
                {
                    current_A_node = current_A_node -> row_next;
                }
                else if (current_A_node -> col > current_B_node -> row)
                {
                    current_B_node = current_B_node -> col_next;
                }
                else
                {
                    multiple_element += (current_A_node -> value) * (current_B_node -> value);
                    current_A_node = current_A_node -> row_next;
                    current_B_node = current_B_node -> col_next;
                }
            }

            insert_value(result_matrix, r, c, multiple_element);
        }
    }
    return result_matrix;
}

void print_sparse_matrix(SparseMatrix* matrix)
{
    for (int r = 0; r < matrix -> rows; r++)
    {
        Node* current = matrix -> row_heads[r];
        while (current)
        {
            printf("(%d, %d, %d) ", current -> row, current -> col, current -> value);
            current = current -> row_next;
        }
        printf("\n");
    }
}

void free_sparse_matrix(SparseMatrix* matrix)
{
    for (int r = 0; r < matrix -> rows; r++)
    {
        Node* current = matrix -> row_heads[r];
        while (current)
        {
            Node* temp = current;
            current = current -> row_next;
            free(temp);
        }
    }
    free(matrix -> row_heads);
    free(matrix -> col_heads);
    free(matrix);
}

int main(void)
{
    SparseMatrix* A = create_sparse_matrix(3, 3);
    SparseMatrix* B = create_sparse_matrix(3, 3);

    insert_value(A, 0, 0, 1);
    insert_value(A, 0, 1, 2);
    insert_value(A, 1, 2, 3);
    insert_value(A, 2, 0, 4);
    insert_value(A, 2, 2, 5);

    insert_value(B, 0, 1, 6);
    insert_value(B, 1, 2, 7);
    insert_value(B, 2, 0, 8);
    insert_value(B, 2, 2, 9);

    SparseMatrix* C = multi_sparse_matrices(A, B);

    printf("\nResultant Matrix C (A * B):\n");
    print_sparse_matrix(C);

    free_sparse_matrix(A);
    free_sparse_matrix(B);
    free_sparse_matrix(C);

    return 0;
}