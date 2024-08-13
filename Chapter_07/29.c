/* Chapter 7 exercise 29 */

/* (프로젝트) 연습 문제 28번에 기술된 아이디어를 사용하여, 원소의 개수가 32개
 * 이하인 집합들을 다루는 완전한 집합 패키지를 개발하여라. 따라서, 다음과 같은
 * 함수들을 작성해야 한다.
 
    set Union(set a, set b);
    set intersection(set a, set b);
    set complement(set a);

 * 위 함수를 작성하고 검사한 후, 더 큰 집합을 다룰 수 있도록 int 배열을 사용하
 * 는 함수로 수정하여라. 단 각 집합의 원소의 개수는 최대 1000개라고 가정한다.
 */

#include <stdio.h>

#define MAX_ELEMENTS 1000
#define INT_SIZE 32
#define ARRAY_SIZE ((MAX_ELEMENTS + INT_SIZE - 1) / INT_SIZE)

// Define set as an array of unsigned integers
typedef unsigned int set[ARRAY_SIZE];

// Function to perform union of two sets
void set_union(set a, set b, set result) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = a[i] | b[i];
    }
}

// Function to perform intersection of two sets
void set_intersection(set a, set b, set result) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = a[i] & b[i];
    }
}

// Function to find the complement of a set
void set_complement(set a, set result) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = ~a[i];
    }
}

// Function to display a set
void display(set a) {
    printf("{ ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < INT_SIZE; j++) {
            if ((a[i] >> j) & 1) {
                printf("%d ", (i * INT_SIZE + j)); // Corrected index calculation
            }
        }
    }
    printf("}\n");
}

int main(void) {
    set a = {0x7}; // Initialize as an array
    set b = {0x55};
    set result;

    set_union(a, b, result); // Pass result array to store the union
    printf("Union: ");
    display(result);

    set_intersection(a, b, result); // Pass result array to store the intersection
    printf("Intersection: ");
    display(result);

    set_complement(a, result); // Pass result array to store the complement
    printf("Complement of a: ");
    display(result);

    return 0;
}
