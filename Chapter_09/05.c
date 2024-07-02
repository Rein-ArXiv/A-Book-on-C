/* Chapter 9 exercise 5 */

/* 수행속도가 프로그램의 목적은 아니지만, 전산학에서는 많이 고려된다. 구조체가
 * 클 경우, 함수를 호출할 때, 구조체 자체를 전달하는 것보다 구조체의 주소를 전
 * 달하는 것이 더 효율적이다. 구조체의 크기가 작을 경우에도 그러한가? 결국, 포
 * 인터를 다루는 데도 비용이 존재한다. 많은 복소수를 곱해야 한다고 가정하자. 이
 * 때 곱하기 함수를 어떻게 설계해야 하는가? 인자로써 구조체를 전달할 수도 있다.
 
    complex mult(complex b, complex c)
    {
        complex a;

        a.re = b.re * c.re - b.im * c.im;
        a.im = b.im * c.re + b.re * c.im;
        return a;
    }

 * 그러나 구조체의 주소를 인자로 전달하는 것이 더 빠를 것이다.

    void mult(complex *a, complex *b, complex *c)
    {
        .....
    }

 * 구조체의 주소를 전달하는 mult() 함수를 완성하고, 위의 두 함수 중 어느 함수
 * 의 수행 속도가 빠른지를 검사하는 프로그램을 작성하여 실행해 보아라.
 */

#include <stdio.h>
#include <time.h>

typedef struct complex {
    double re;
    double im;
} complex;

complex mult_argu(complex b, complex c);
void mult_ptr(complex *a, complex *b, complex *c);

int main(void)
{
    complex a, b, c;
    
    b.re = 1.0;
    b.im = 2.0;

    c.re = 3.0;
    b.im = 4.0;

    // 반복 횟수
    int iterations = 1000000;
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (int i = 0; i < iterations; i++) {
        a = mult_argu(b, c);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by mult_argu: %f seconds\n", cpu_time_used);

    // mult_ptr 함수의 수행 시간 측정
    start = clock();
    for (int i = 0; i < iterations; i++) {
        mult_ptr(&a, &b, &c);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by mult_ptr: %f seconds\n", cpu_time_used);

    return 0;
}


complex mult_argu(complex b, complex c)
{
    complex a;

    a.re = b.re * c.re - b.im * c.im;
    a.im = b.im * c.re + b.re * c.im;
    return a;
}

void mult_ptr(complex *a, complex *b, complex *c)
{
    a -> re = b -> re * c -> re - b -> im * c -> im; 
    a -> im = b -> im * c -> re + b -> re * c -> im;

}