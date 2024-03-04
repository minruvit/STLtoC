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

// O(N)
void deleteSinglyLinkedList(singlyLinkedList*);

// insert into front(idx = 0) : O(1)
// insert into back(idx = -1) : O(N)
// insert into specific index : O(N)
void insertSinglyLinkedList(singlyLinkedList * const, int const, int const);

// search by value : O(N)
// print nodes' index
void searchSinglyLinkedList(singlyLinkedList const * const, int const);

// use member variable
int lengthSinglyLinkedList(singlyLinkedList const * const);

void reverseSinglyLinkedList(singlyLinkedList * const);

// remove all node having such value
void removeByValueSinglyLinkedList(singlyLinkedList * const, int const);
// remove node in such index
void removeByIndexSinglyLinkedList(singlyLinkedList * const, int const);

// print singly linked list
void printSinglyLinkedList(singlyLinkedList const * const);
