/* Chapter 10 exercise 18 */

/* 다음 수식의 폴리시 수식을 써라.

    (7 + 8 + 9) * 4
    (6 - 2) * (5 + 15 * 2)
    6 - 2 * 5 + 15 * 2

 */

/* 78+9+4*
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>

#define EMPTY   0
#define FULL    10000

typedef struct data {
    enum {operator, value} kind;
    union {
        char op;
        int val;
    } u;
} data;

typedef struct elem {               // an element on the stack
    data d;
    struct elem *next;
} elem;

typedef struct stack {              
    int cnt;                // a count of elements
    elem *top;              // ptr to the top element
} stack;

