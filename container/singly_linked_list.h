/* If necessary, change the data type. */
/* Reference : https://www.geeksforgeeks.org/data-structures/linked-list/singly-linked-list/ */

/// Including header
#include <stdlib.h>     // include for malloc, free


/// Structure definition
// structure for nodes in singly linked list.
typedef struct singlyLinkedListNode {
    int data;
    struct singlyLinkedListNode* nextNode;
} singlyLinkedListNode;

// structure for singly linked list
typedef struct singlyLinkedList {
    unsigned int size;
    singlyLinkedListNode* head;
} singlyLinkedList;


/// Function declaration
singlyLinkedList* makeSinglyLinkedList();
void deleteSinglyLinkedList(singlyLinkedList*);
int insertSinglyLinkedList(singlyLinkedList * const, int const, int const);
void searchSinglyLinkedList(singlyLinkedList const * const, int const);
int lengthSinglyLinkedList(singlyLinkedList const * const);
// void reverseSinglyLinkedList(singlyLinkedList * const); --> need to implemented
void removeByValueSinglyLinkedList(singlyLinkedList * const, int const);
int removeByIndexSinglyLinkedList(singlyLinkedList * const, int const);
void printSinglyLinkedList(singlyLinkedList const * const);


/// Make singly linked list
singlyLinkedList* makeSinglyLinkedList() {
    singlyLinkedList* newSinglyLinkedList = malloc(sizeof(singlyLinkedList));
    singlyLinkedListNode* newSinglyLinkedListHead = malloc(sizeof(singlyLinkedListNode));
    newSinglyLinkedListHead->nextNode = NULL;
    newSinglyLinkedList->size = 0;
    newSinglyLinkedList->head = newSinglyLinkedListHead;

    return newSinglyLinkedList;
}

/// Delete singly linked list
void deleteSinglyLinkedList(singlyLinkedList* sll) {
    singlyLinkedListNode* curr = sll->head;
    singlyLinkedListNode* next;
    while(curr->nextNode != NULL) {
        next = curr->nextNode;
        free(curr);
        curr = next;
    }
    free(sll->head);
    free(sll);

    return;
}

/// Insert node
// insert into front(idx = 0) : O(1)
// insert into back(idx = -1) : O(N)
// insert into specific index : O(N)
int insertSinglyLinkedList(singlyLinkedList * const sll, int const index, int const value){
    if (index > sll->size)  return -1;

    singlyLinkedListNode* newSinglyLinkedListNode = malloc(sizeof(singlyLinkedListNode));
    newSinglyLinkedListNode->data = value;
    if(index == 0) {
        newSinglyLinkedListNode->nextNode = sll->head->nextNode;
        sll->head->nextNode = newSinglyLinkedListNode;
    }
    else if(index == -1) {
        singlyLinkedListNode* iter = sll->head;
        while(iter->nextNode != NULL)
            iter = iter->nextNode;
        newSinglyLinkedListNode->nextNode = NULL;
        iter->nextNode = newSinglyLinkedListNode;
    }
    else {
        singlyLinkedListNode* iter = sll->head;
        for(int i = 0; i < index; i++)
            iter = iter->nextNode;
        newSinglyLinkedListNode->nextNode = iter->nextNode;
        iter->nextNode = newSinglyLinkedListNode;
    }
    sll->size++;

    return 0;
}

/// Search node
// search by value : O(N)
// print nodes' index
void searchSinglyLinkedList(singlyLinkedList const * const sll, int const value) {
    singlyLinkedListNode* iter = sll->head;
    int index = 0;
    while(iter->next != NULL) {
        iter = iter->next;
        if(iter->data == value)  printf("%d ", index);
        index++;
    }
    printf("\n");

    return;
}

/// Size of singly linked list
// use member variable
int lengthSinglyLinkedList(singlyLinkedList const * const sll) {
    printf("%d\n", sll->size);

    return sll->size;
}

/// Remove nodes by key
// remove all node having such key value
void removeByValueSinglyLinkedList(singlyLinkedList * const sll, int const value) {
    singlyLinkedListNode* curr = sll->head;
    singlyLinkedListNode* prev;
    while(curr->nextNode != NULL) {
        prev = curr;
        curr = curr->nextNode;
        if(curr->data == value) {
            prev->nextNode = curr->nextNode;
            free(curr);
            curr = prev;
            sll->size--;
        }
    }

    return;
}

/// Remove a node by index
// remove node in such index
int removeByIndexSinglyLinkedList(singlyLinkedList * const sll, int const index) {
    if(index > sll->size-1)  return -1;

    singlyLinkedListNode* curr = sll->head;
    singlyLinkedListNode* prev;
    for(int i = 0; i < index; i++) {
        prev = curr;
        curr = curr->nextNode;
    }
    prev->nextNode = curr->nextNode;
    free(curr);
    sll->size--;

    return 0;
}

/// Print singly linked list
void printSinglyLinkedList(singlyLinkedList const * const sll) {
    singlyLinkedListNode* iter = sll->head;
    while(iter->next != NULL) {
        iter = iter->next;
        printf("%d ", iter->data);
    }
    printf("\n");

    return;
}
