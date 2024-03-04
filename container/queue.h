/* If necessary, change the data type. */
/* Reference : https://en.cppreference.com/w/cpp/container/queue */

/// Including header
#include <stdlib.h>     // include for malloc, free


/// Structure definition
// structure for elements in queue.
typedef struct queueElement {
    int data;
    struct queueElement* nextElement;
} queueElement;

// structure for queue.
typedef struct queue {
    unsigned int size;
    queueElement* head;
    queueElement* backElement;
} queue;


/// Function declaration
queue* makeQueue();
void deleteQueue(queue*);
int frontQueue(queue const * const);
int backQueue(queue const * const);
int emptyQueue(queue const * const);
int sizeQueue(queue const * const);
void pushQueue(queue * const, int const);
void popQueue(queue * const);
void swapQueue(queue const **, queue const **);


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
        popQueue(que);
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
int emptyQueue(queue const * const que) {
    return que->size == 0 ? 1 : 0;
}

// size
int sizeQueue(queue const * const que) {
    return que->size;
}

/// Modifiers
// push
void pushQueue(queue * const que, int const value) {
    queueElement* newElement = (queueElement*)malloc(sizeof(queueElement));
    newElement->data = value;
    newElement->nextElement = NULL;
    que->backElement->nextElement = newElement;
    que->backElement = newElement;
    que->size++;

    return;
}

// pop
void popQueue(queue * const que) {
    if(!que->size)  return;
    queueElement* temp = que->head->nextElement;
    que->head->nextElement = que->head->nextElement->nextElement;
    free(temp);
    que->size--;

    return;
}

// swap (C++11)
void swapQueue(queue const ** pQue_1, queue const ** pQue_2) {
    queue* temp = *pQue_1;
    *pQue_1 = *pQue_2;
    *pQue_2 = temp;

    return;
}
