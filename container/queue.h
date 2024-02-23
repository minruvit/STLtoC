/* If necessary, change the data type. */

/// Including header
#include <stdlib.h>     // include for malloc, free


/// Structure definition
// struct for elements in queue.
typedef struct queueElement {
    int data;
    struct queueElement* nextElement;
} queueElement;

// struct for queue.
typedef struct queue {
    unsigned int size;
    queueElement* head;
    queueElement* backElement;
} queue;


/// Function declaration
queue* makeQueue();
void deleteQueue(queue*);
int queueFront(queue const * const);
int queueBack(queue const * const);
int queueEmpty(queue const * const);
int queueSize(queue const * const);
void queuePush(queue * const, int const);
void queuePop(queue * const);
void queueSwap(queue const **, queue const **);


/// Make queue
queue* makeQueue() {
    queue* newQueue = (queue*)malloc(sizeof(queue));
    newQueue->size = 0;
    queueElement* newHead = (queueElement*)malloc(sizeof(queueElement));
    newQueue->head = newHead;
    newQueue->backElement = newHead;

    return newQueue;
}

/// Delete queue
void deleteQueue(queue* que) {
    while(que->size)
        queuePop(que);
    free(que->head);
    free(que);

    return;
}

/// Element access
// front
int queueFront(queue const * const que) {
    return que->head->nextElement->data;
}

// back
int queueBack(queue const * const que) {
    return que->backElement->data;
}

/// Capacity
// empty
int queueEmpty(queue const * const que) {
    return que->size == 0 ? 1 : 0;
}

// size
int queueSize(queue const * const que) {
    return que->size;
}

/// Modifiers
// push
void queuePush(queue * const que, int const value) {
    queueElement* newElement = (queueElement*)malloc(sizeof(queueElement));
    newElement->data = value;
    newElement->nextElement = NULL;
    que->backElement->nextElement = newElement;
    que->backElement = newElement;
    que->size++;

    return;
}

// pop
void queuePop(queue * const que) {
    if(!que->size)  return;
    queueElement* temp = que->head->nextElement;
    que->head->nextElement = que->head->nextElement->nextElement;
    free(temp);
    que->size--;

    return;
}

// swap (C++11)
void queueSwap(queue const ** pQue1, queue const ** pQue2) {
    queue* temp = *pQue1;
    *pQue1 = *pQue2;
    *pQue2 = temp;

    return;
}
