/* In file polish.h */
/* A linked list implementation of a Polish stack */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define EMPTY   0
#define FULL    10000

struct data {
    enum {operator, value, braket} kind;
    union {
        char op;
        int val;
    } u;
};

typedef struct data data;
typedef enum {false, true} boolean;

struct elem {               // an element on the stack
    data d;
    struct elem *next;
};

typedef struct elem elem;

struct stack {
    int cnt;                // a count of the elements
    elem *top;              // ptr to the top element
};

typedef struct stack stack;

// Stack operation
void initialize(stack *dp);
void push(data d, stack *stk);
data pop(stack *stk);
data top(stack *stk);
boolean empty(const stack *stk);
boolean full(const stack *stk);
void reverse_stack(stack *stk);     // for exercise 21


// Expression processing
int evaluate(stack *polish);
void fill(stack *stk, const char *str);

// Utility functions
void prn_data(data *dp);
void prn_stack(stack *stack);