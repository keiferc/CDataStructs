/*
 *      filename:       dlinkedlist.c
 *      author:         @keiferchiang
 *      date:           2 May 2018
 *      version:        0.0.1
 *
 *      description:    Implementation of the DLinkedList module
 *
 *      note:           This implementation of DLinkedList is
 *                      lightly optimized for end-node manipulation,
 *                      trading off memory conservation. The
 *                      optimization allows the DLinkedList to be a
 *                      base for LIFO and FIFO data structures while
 *                      allowing said structures to run most
 *                      operations with a time complexity of O(1)
 */

#include "dlinkedlist.h"

/*-------------------------------------
 * Representation
 -------------------------------------*/
typedef struct node_t {
        void *elem;
        struct node *next;
        struct node *prev;
} *Node_T;

struct dlinkedlist_t {
        Node_T front;
        Node_T tail;
        unsigned capacity;
        unsigned size;
};

/*-------------------------------------
 * Helper/Private Prototypes
 -------------------------------------*/


/*-------------------------------------
 * Function Definitions
 -------------------------------------*/
DLinkedList_T DLinkedList_new(unsigned hint)
{
        (void) hint;
        return NULL;
}

void DLinkedList_free(DLinkedList_T *list)
{
        (void) list;
}

//////////////////////////////////
//      Getter Functions        //
//////////////////////////////////
unsigned DLinkedList_length(DLinkedList_T list)
{
        (void) list;
        return 0;
}

void *DLinkedList_get(DLinkedList_T list, unsigned index)
{
        (void) list, (void) index;
        return NULL;
}

void *DLinkedList_gethi(DLinkedList_T list)
{
        (void) list;
        return NULL;
}

void *DLinkedList_getlo(DLinkedList_T list)
{
        (void) list;
        return NULL;
}

//////////////////////////////////
//      Setter Functions        //
//////////////////////////////////
void DLinkedList_set(DLinkedList_T list, void *elem, unsigned index)
{
        (void) list, (void) elem, (void) index;
}

void DLinkedList_sethi(DLinkedList_T list, void *elem)
{
        (void) list, (void) elem;
}

void DLinkedList_setlo(DLinkedList_T list, void *elem)
{
        (void) list, (void) elem;
}

//////////////////////////////////
//      Remove Functions        //
//////////////////////////////////
void DLinkedList_remove(DLinkedList_T list, unsigned index)
{
        (void) list, (void) index;
}

void DLinkedList_removehi(DLinkedList_T list)
{
        (void) list;
}

void DLinkedList_removelo(DLinkedList_T list)
{
        (void) list;
}

/*-------------------------------------
 * Helper/Private Definitions
 -------------------------------------*/
