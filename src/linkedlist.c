/*
 *      filename:       linkedlist.c
 *      author:         @keiferchiang
 *      date:           2 May 2018
 *      version:        0.0.1
 *
 *      description:    Implementation of the LinkedList module
 *
 *      note:           This implementation of LinkedList is
 *                      lightly optimized for end-node manipulation,
 *                      trading off memory conservation. The
 *                      optimization allows the LinkedList to be a
 *                      base for LIFO and FIFO data structures while
 *                      allowing said structures to run most
 *                      operations with a time complexity of O(1)
 */

#include "linkedlist.h"

/*-------------------------------------
 * Representation
 -------------------------------------*/
typedef struct node_t {
        void *elem;
        struct node *next;
        struct node *prev;
} *Node_T;

struct linkedlist_t {
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
LinkedList_T LinkedList_new(unsigned hint)
{
        (void) hint;
        return NULL;
}

void LinkedList_free(LinkedList_T *list)
{
        (void) list;
}

//////////////////////////////////
//      Getter Functions        //
//////////////////////////////////
unsigned LinkedList_length(LinkedList_T list)
{
        (void) list;
        return 0;
}

void *LinkedList_get(LinkedList_T list, unsigned index)
{
        (void) list, (void) index;
        return NULL;
}

void *LinkedList_gethi(LinkedList_T list)
{
        (void) list;
        return NULL;
}

void *LinkedList_getlo(LinkedList_T list)
{
        (void) list;
        return NULL;
}

//////////////////////////////////
//      Setter Functions        //
//////////////////////////////////
void LinkedList_set(LinkedList_T list, void *elem, unsigned index)
{
        (void) list, (void) elem, (void) index;
}

void LinkedList_sethi(LinkedList_T list, void *elem)
{
        (void) list, (void) elem;
}

void LinkedList_setlo(LinkedList_T list, void *elem)
{
        (void) list, (void) elem;
}

//////////////////////////////////
//      Remove Functions        //
//////////////////////////////////
void LinkedList_remove(LinkedList_T list, unsigned index)
{
        (void) list, (void) index;
}

void LinkedList_removehi(LinkedList_T list)
{
        (void) list;
}

void LinkedList_removelo(LinkedList_T list)
{
        (void) list;
}

/*-------------------------------------
 * Helper/Private Definitions
 -------------------------------------*/
