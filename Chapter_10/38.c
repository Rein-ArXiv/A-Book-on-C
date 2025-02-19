/* Chapter 10 exercise 38 */

/* 희소행렬의 덧셈 프로그램을 위하여 일반적인 연결 리스트 구조를 사용하여라. 희
 * 소행렬은 대부분의 원소 값이 0이다. 희소행렬의 0이 아닌 원소는 (i, j, value) 트
 * 리플로 표현된다. i 행에 대한 트리플은 배열 포인터 row[i]를 헤드로 하여 선형
 * 리스트로 연결된다. 마찬가지로 j 열에 대한 트리플은 col[j]를 헤드로 하는 선
 * 형 리스트로 연결된다. 행렬 A에 행렬 B를 더하기 위해서는 A와 B에서 대응하는
 * 행을 하나로 합병하여 행렬 C의 행으로 만들어야 한다. 만일 두 행의 리스트에서
 * 같은 열 값을 갖는 트리플이 있으면, 출력 행에서 c_ij는 a_ij + b_ij이다. 그렇지
 * 않다면, 둘 중 작은 열 값을 갖는 원소가 출력 행의 다음 원소가 된다.
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
        printf("Memory allocation failed.\n");
        exit(1);
    }

    matrix -> rows = rows;
    matrix -> cols = cols;

    matrix -> row_heads = (Node**)calloc(rows, sizeof(Node*));
    matrix -> col_heads = (Node**)calloc(cols, sizeof(Node*));

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

SparseMatrix* add_sparse_matrices(SparseMatrix* A, SparseMatrix* B)
{
    if (A -> rows != B -> rows || A -> cols != B -> cols)
    {
        printf("Matrices sizes are not the same.\n");
        return NULL;
    }
    int rows = A -> rows;
    int cols = A -> cols;
    
    SparseMatrix* result_matrix = create_sparse_matrix(rows, cols);

    for (int r = 0; r < rows; r++)
    {
        Node* current_A_node = A -> row_heads[r];
        Node* current_B_node = B -> row_heads[r];

        while (current_A_node || current_B_node)
        {
            // 만약 특정 행렬 원소에서 행렬 B의 원소 값이 0이고, 행렬 A는 값을 가질 경우
            if (current_A_node && (!current_B_node || (current_A_node -> col < current_B_node -> col)))
            {
                insert_value(result_matrix, r, current_A_node -> col, current_A_node -> value);
                current_A_node = current_A_node -> row_next;
            }

            else if (current_B_node && (!current_A_node || (current_B_node -> col < current_A_node -> col)))
            {
                insert_value(result_matrix, r, current_B_node -> col, current_B_node -> value);
                current_B_node = current_B_node -> row_next;
            }
            else
            {
                int sum = current_A_node -> value + current_B_node -> value;
                
                if (sum != 0)
                {
                    insert_value(result_matrix, r, current_A_node -> col, sum);
                }
                current_A_node = current_A_node -> row_next;
                current_B_node = current_B_node -> row_next;
            }
        }
    }

    return result_matrix;
}

void print_sparse_matrix(SparseMatrix* matrix)
{
    for (int r = 0; r < matrix->rows; r++)
    {
        Node* current = matrix->row_heads[r];
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
    free(matrix->row_heads);
    free(matrix->col_heads);
    free(matrix);
}

int main(void)
{
    SparseMatrix* A = create_sparse_matrix(3, 3);
    SparseMatrix* B = create_sparse_matrix(3, 3);

    insert_value(A, 0, 0, 3);
    insert_value(A, 1, 1, 5);
    insert_value(A, 2, 2, 7);

    insert_value(B, 0, 0, 1);
    insert_value(B, 1, 2, 2);
    insert_value(B, 2, 2, -7);

    printf("Matrix A:\n");
    print_sparse_matrix(A);

    printf("\nMatrix B:\n");
    print_sparse_matrix(B);

    SparseMatrix* C = add_sparse_matrices(A, B);

    printf("\nResultant Matrix C (A + B):\n");
    print_sparse_matrix(C);

    // 메모리 해제
    free_sparse_matrix(A);
    free_sparse_matrix(B);
    free_sparse_matrix(C);

    return 0;
}