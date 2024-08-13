/* Chapter 9 exercise 4 */

/* 행렬 a와 b를 더해 c에 저장하는 함수 add(a, b, c)를 작성하고, 이 함수를 사
 * 용하는 프로그램을 작성하여 수행시켜 보아라.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix{
    int rows;
    int cols;
    double data[];
} Matrix;

Matrix* createMatrix(int rows, int cols)
{
    // Matrix 구조체를 저장할 메모리 크기 + 행렬 데이터를 저장할 메모리 크기
    Matrix* m = (Matrix*)malloc(sizeof(Matrix) + rows * cols * sizeof(double));

    m -> rows = rows;
    m -> cols = cols;
    return m;
}

void initializeMatrix(Matrix *m, double values[])
{
    int size = m -> rows * m -> cols;
    for (int i = 0; i < size; i++) {
        m -> data[i] = values[i];
    }
}

void add(const Matrix* a, const Matrix* b, Matrix* c)
{
    if (a -> rows != b -> rows || a -> cols != b -> cols) {
        printf("ERROR: Matrix size is different.\n");
        return;
    }

    c -> rows = a -> rows;
    c -> cols = a -> cols;

    int size = a -> rows * a -> cols;
    for (int i = 0; i < size; i++){
        c -> data[i] = a -> data[i] + b -> data[i];
    }
}

int main()
{
    double a_data[] = {1, 2, 3, 4, 5, 6};
    double b_data[] = {7, 8, 9, 10, 11, 12};

    Matrix* a = createMatrix(2, 3);
    Matrix* b = createMatrix(2, 3);

    initializeMatrix(a, a_data);
    initializeMatrix(b, b_data);

    Matrix* c = createMatrix(2, 3);
    add(a, b, c);

    printf("Matrix C:\n");

    for (int i = 0; i < c -> rows; i++){
        for (int j = 0; j < c -> cols; j++){
            printf("%.1lf ", c -> data[i * c -> cols + j]);
        }
        printf("\n");
    }

    free(a);
    free(b);
    free(c);

    return 0;
}