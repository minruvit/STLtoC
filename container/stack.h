/* If necessary, change the data type. */
/* Reference : https://en.cppreference.com/w/cpp/container/stack */

/// Including header
#include <stdlib.h>     // include for malloc, free


/// Structure definition
// structure for elements in stack.
typedef struct stackElement {
    int data;
    struct stackElement* prevElement;
} stackElement;

// structure for stack.
typedef struct stack {
    unsigned int size;
    stackElement* topElement;
} stack;


/// Function declaration
stack* makeStack();
void deleteStack(stack*);
int topStack(stack const * const);
int emptyStack(stack const * const);
int sizeStack(stack const * const);
void pushStack(stack * const, int const);
void popStack(stack * const);
void swapStack(stack const **, stack const **);


/// Make stack
stack* makeStack() {
    stack* newStack = malloc(sizeof(stack));
    newStack->size = 0;
    newStack->topElement = NULL;

    return newStack;
}

/// Delete Stack
void deleteStack(stack* stk) {
    while(stk->size)
        popStack(stk);
    free(stk);

    return;
}

/// Element access
// top
int topStack(stack const * const stk) {
    return stk->topElement->data;
}

/// Capacity
// empty
int emptyStack(stack const * const stk) {
    return stk->size == 0 ? 1 : 0;
}

// size
int sizeStack(stack const * const stk) {
    return stk->size;
}

/// Modifiers
// push
void pushStack(stack * const stk, int const value) {
    stackElement* newElement = (stackElement*)malloc(sizeof(stackElement));
    newElement->data = value;
    newElement->prevElement = stk->topElement;
    stk->topElement = newElement;
    stk->size++;

    return;
}

// pop
void popStack(stack * const stk) {
    if(!stk->size)  return;
    stackElement* temp = stk->topElement;
    stk->topElement = stk->topElement->prevElement;
    free(temp);
    stk->size--;

    return;
}

// swap (C++11)
void swapStack(stack const ** pStk_1, stack const ** pStk_2) {
    stack* temp = *pStk_1;
    *pStk_1 = *pStk_2;
    *pStk_2 = temp;

    return;
}
