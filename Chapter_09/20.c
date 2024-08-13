/* Chapter 9 exercise 20 */

/* 다음과 같은 두 멤버를 갖는 구조체를 위한 typedef를 작성하여라. 한 멤버는
 * double 멤버와 complex 멤버를 갖는 공용체이고, 다른 멤버는 공용체의 어느 멤
 * 버를 사용하고 있는가를 표시하는 "flag"이다. 그 다음 double과 complex 두 도
 * 메인에 대한 덧셈과 곱셈을 수행하는 함수를 작성하여라. 작성된 함수는 덧셈과
 * 곱셈의 두 인자의 도메인이 다른 경우 적절한 변환을 결정할 수 있어야 한다.
 */

#include <stdio.h>

typedef struct complex {
    double re;
    double im;
} complex;

typedef union value_union {
    double doub;
    complex comp;
} value_union;

typedef struct number {
    value_union value;
    enum { REAL, COMPLEX } flag;
} number;

number add(number a, number b)
{
    number result;

    if (a.flag == REAL && b.flag == REAL) {
        result.flag = REAL;
        result.value.real = a.value.real + b.value.real;
    } else if (a.flag == COMPLEX && b.flag == COMPLEX) {
        result.flag = COMPLEX;
        result.value.comp.re = a.value.comp.re + b.value.comp.re;
        result.value.comp.im = a.value.comp.im + b.value.comp.im;
    } else {
        result.flag = COMPLEX;
        if (a.flag == REAL) {
            result.value.comp.re = a.value.real + b.value.comp.re;
            result.value.comp.im = b.value.comp.im;
        } else {
            result.value.comp.re = a.value.comp.re + b.value.real;
            result.value.comp.im = a.value.comp.im;
        }
    }
    return result;
}

number multiply(number a, number b)
{
    number result;
    
    if (a.flag == REAL && b.flag == REAL) {
        result.flag = REAL;
        result.value.real = a.value.real * b.value.real;
    } else if (a.flag == COMPLEX && b.flag == COMPLEX) {
        result.flag = COMPLEX;
        result.value.comp.re = a.value.comp.re * b.value.comp.re - a.value.comp.im * b.value.comp.im;
        result.value.comp.im = a.value.comp.re * b.value.comp.im + a.value.comp.im * b.value.comp.re;
    } else {
        result.flag = COMPLEX;
        if (a.flag == REAL) {
            result.value.comp.re = a.value.real * b.value.comp.re;
            result.value.comp.im = a.value.real * b.value.comp.im;
        } else {
            result.value.comp.re = a.value.comp.re * b.value.real;
            result.value.comp.im = a.value.comp.im * b.value.real;
        }
    }
    return result;
}

int main(void) {
    number x, y, result;

    // Example 1: both REAL
    x.flag = REAL;
    x.value.real = 5.0;
    y.flag = REAL;
    y.value.real = 3.0;
    result = add(x, y);
    if (result.flag == REAL)
        printf("Addition Result: %lf\n", result.value.real);

    // Example 2: both COMPLEX
    x.flag = COMPLEX;
    x.value.comp.re = 1.0;
    x.value.comp.im = 2.0;
    y.flag = COMPLEX;
    y.value.comp.re = 3.0;
    y.value.comp.im = 4.0;
    result = add(x, y);
    if (result.flag == COMPLEX)
        printf("Addition Result: %lf + %lfi\n", result.value.comp.re, result.value.comp.im);

    // Example 3: one REAL, one COMPLEX
    x.flag = REAL;
    x.value.real = 2.0;
    y.flag = COMPLEX;
    y.value.comp.re = 3.0;
    y.value.comp.im = 4.0;
    result = add(x, y);
    if (result.flag == COMPLEX)
        printf("Addition Result: %lf + %lfi\n", result.value.comp.re, result.value.comp.im);

    return 0;
}
