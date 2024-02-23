/* If necessary, change the data type. */

/// Including header
#include <stdlib.h>     // include for malloc, free


/// Structure definition
// struct for elements in stack.
typedef struct stackElement {
    int data;
    struct stackElement* prevElement;
} stackElement;

// struct for stack.
typedef struct stack {
    unsigned int size;
    stackElement* topElement;
} stack;


/// Function declaration
stack* makeStack();
void deleteStack(stack*);
int stackTop(stack const * const);
int stackEmpty(stack const * const);
int stackSize(stack const * const);
void stackPush(stack * const, int const);
void stackPop(stack * const);
void stackSwap(stack const **, stack const **);


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
        stackPop(stk);
    free(stk);

    return;
}

/// Element access
// top
int stackTop(stack const * const stk) {
    return stk->topElement->data;
}

/// Capacity
// empty
int stackEmpty(stack const * const stk) {
    return stk->size == 0 ? 1 : 0;
}

// size
int stackSize(stack const * const stk) {
    return stk->size;
}

/// Modifiers
// push
void stackPush(stack * const stk, int const value) {
    stackElement* newElement = (stackElement*)malloc(sizeof(stackElement));
    newElement->data = value;
    newElement->prevElement = stk->topElement;
    stk->topElement = newElement;
    stk->size++;

    return;
}

// pop
void stackPop(stack * const stk) {
    if(!stk->size)  return;
    stackElement* temp = stk->topElement;
    stk->topElement = stk->topElement->prevElement;
    free(temp);
    stk->size--;

    return;
}

// swap (C++11)
void stackSwap(stack const ** pStk1, stack const ** pStk2) {
    stack* temp = *pStk1;
    *pStk1 = *pStk2;
    *pStk2 = temp;

    return;
}
