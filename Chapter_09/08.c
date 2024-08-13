/* Chapter 9 exercise 8 */

/* 복소수 벡터와 행렬에 연산을 수행하는 함수들을 작성하여라. 화면에 복소수 벡터
 * 와 행렬을 출력하는 함수도 작성해야 한다. 작성한 함수들을 검사하는 프로그램을
 * 작성하여라.
 */

#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct complex {
    double re;
    double im;
} complex;

typedef struct matrix {
    int rows;
    int cols;
    double data[MAX_ROWS][MAX_COLS];
} matrix;

void print_complex(complex c);
void print_matrix(matrix m);

complex add_complex(complex a, complex b);
complex multiply_complex(complex a, complex b);

matrix add_matrices(matrix a, matrix b);
matrix multiply_matrices(matrix a, matrix b);

int main() {
    complex a = {1.0, 2.0};
    complex b = {3.0, 4.0};

    printf("Complex numbers:\n");
    printf("a = ");
    print_complex(a);
    printf("\nb = ");
    print_complex(b);

    complex sum = add_complex(a, b);
    complex product = multiply_complex(a, b);

    printf("\n\na + b = ");
    print_complex(sum);
    printf("\na * b = ");
    print_complex(product);

    matrix m1 = {2, 2, {{1, 2}, {3, 4}}};
    matrix m2 = {2, 2, {{5, 6}, {7, 8}}};

    printf("\n\nMatrices:\n");
    printf("Matrix 1:\n");
    print_matrix(m1);
    printf("Matrix 2:\n");
    print_matrix(m2);

    matrix m_sum = add_matrices(m1, m2);
    matrix m_product = multiply_matrices(m1, m2);

    printf("\nMatrix 1 + Matrix 2:\n");
    print_matrix(m_sum);
    printf("Matrix 1 * Matrix 2:\n");
    print_matrix(m_product);

    return 0;
}

void print_complex(complex c) {
    printf("(%.2f, %.2f)", c.re, c.im);
}

void print_matrix(matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%.2f ", m.data[i][j]);
        }
        printf("\n");
    }
}

complex add_complex(complex a, complex b) {
    complex result;
    result.re = a.re + b.re;
    result.im = a.im + b.im;
    return result;
}

complex multiply_complex(complex a, complex b) {
    complex result;
    result.re = a.re * b.re - a.im * b.im;
    result.im = a.re * b.im + a.im * b.re;
    return result;
}

matrix add_matrices(matrix a, matrix b) {
    matrix result = {a.rows, a.cols, {{0}}};
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Error: Matrices dimensions do not match for addition.\n");
        return result;
    }
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

matrix multiply_matrices(matrix a, matrix b) {
    matrix result = {a.rows, b.cols, {{0}}};
    if (a.cols != b.rows) {
        printf("Error: Matrices dimensions do not match for multiplication.\n");
        return result;
    }
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}