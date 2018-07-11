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
        struct node_t *next;
        struct node_t *prev;
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
/*
 * Mallocs "hint" empty nodes. Helper to constructor
 */
Node_T malloc_hint(Node_T prev, unsigned hint);

/*
 * Mallocs and inits a new node
 */
Node_T new_node(Node_T prev, Node_T next, void *elem);

/*
 * Removes and frees the given node
 */
void delete_node(Node_T curr);

/*-------------------------------------
 * Function Definitions
 -------------------------------------*/
DLinkedList_T DLinkedList_new(unsigned hint)
{
        DLinkedList_T list;

        list = malloc(sizeof(struct dlinkedlist_t));
        assert(list != NULL);

        list->capacity = hint;
        list->size = 0;

        list->front = malloc_hint(NULL, hint);
        assert(list->front != NULL);

        list->tail = list->front + (hint * sizeof(struct node_t));
        assert(list->tail != NULL);

        return list;
}

void DLinkedList_free(DLinkedList_T *list)
{
        assert(list != NULL);
        assert(*list != NULL);

        //TODO
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
Node_T malloc_hint(Node_T prev, unsigned hint)
{
        Node_T node = NULL;

        if (hint == 0)
                return NULL; 

        // node = malloc(sizeof(struct node_t));
        // assert(node != NULL);

        // node->elem = NULL;
        // node->prev = prev;
        // node->next = malloc_hint(node, hint - 1);

        node = new_node(prev, malloc_hint(node, hint - 1), NULL);
        assert(node != NULL);

        return node;
}

Node_T new_node(Node_T prev, Node_T next, void *elem)
{
        Node_T node = NULL;

        node = malloc(sizeof(struct node_t));
        assert(node != NULL);

        node->elem = elem;
        node->prev = prev;
        node->next = next;

        return node;
}

void delete_node(Node_T curr)
{
        
}
