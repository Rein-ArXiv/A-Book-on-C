/* Chapter 9 exercise 7 */

/* 복소수 뺄셈을 수행하는 함수를 작성하여라. 두 버전을 작성하는데, 한 함수는
 * complex에 대한 포인터를 리턴하고, 다른 함수는 complex 형의 값을 리턴하도록
 * 하여라.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct complex {
    double re;
    double im;
} complex;

complex* subtract_ptr(const complex* a, const complex* b) {
    complex* result = (complex*)malloc(sizeof(complex));
    if (result != NULL) {
        result -> re = a -> re - b -> re;
        result -> im = a -> im - b -> im;
    }
    return result;
}

complex subtract_val(const complex a, const complex b) {
    complex result;
    result.re = a.re - b.re;
    result.im = a.im - b.im;
    return result;
}

int main(void)
{
    complex a = {5.0, 4.0};
    complex b = {3.0, 1.0};

    complex* result_ptr = subtract_ptr(&a, &b);
    complex result_val = subtract_val(a, b);

    if (result_ptr != NULL) {
        printf("subtract_ptr: (%.2f, %.2f)\n", result_ptr -> re, result_ptr -> im);
        free(result_ptr);
    } else {
        printf("Memory allocation failed!\n");
    }

    printf("subtract_val: (%.2f, %.2f)\n", result_val.re, result_val.im);

    return 0;
}