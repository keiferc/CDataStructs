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


//////////////////////////////////
//      Getter Functions        //
//////////////////////////////////


//////////////////////////////////
//      Setter Functions        //
//////////////////////////////////


//////////////////////////////////
//      Remove Functions        //
//////////////////////////////////


/*-------------------------------------
 * Helper/Private Definitions
 -------------------------------------*/
