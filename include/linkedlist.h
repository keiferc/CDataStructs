/*
 *      filename:       linkedlist.c
 *      author:         @keiferchiang
 *      date:           2 May 2018
 *      version:        0.0.1
 *
 *      description:    Interface of the LinkedList module
 */
/*-------------------------------------
 * C Preprocessor Directives
 -------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

/*-------------------------------------
 * Representation
 -------------------------------------*/
typedef struct linkedlist_t *LinkedList_T;

/*-------------------------------------
 * Function Prototypes
 -------------------------------------*/
/*
 * LinkedList_new
 *
 * Given a hint of the default size, creates and returns
 * a pointer to an instance of a LinkedList
 *
 * CREs         n/a
 * UREs         n/a
 *
 * @param       unsigned        Hint of the default size of
 * 				the LinkedList
 * @return      LinkedList_T    A pointer to an instance of
 * 				a linked-list
 */
LinkedList_T LinkedList_new(unsigned hint);

/*
 * LinkedList_free
 *
 * Recycles heap allocated memory for LinkedList. It is the
 * client's responsibility to free every element in the
 * LinkedList before freeing the LinkedList itself
 *
 * CREs         list == NULL
 * UREs         elements in list != NULL
 *
 * @param       LinkedList_T    LinkedList to be freed
 * @return      n/a
 */
void LinkedList_free(LinkedList_T *list);

//////////////////////////////////
//      Getter Functions        //
//////////////////////////////////
/*
 * LinkedList_length
 *
 * Returns the length of the given LinkedList
 *
 * CREs         list == NULL
 * UREs         n/a
 *
 * @param       LinkedList_T    LinkedList whose length is to
 *                              be returned
 * @return      unsigned        Length of the LinkedList
 */
unsigned LinkedList_length(LinkedList_T list);

/*
 * LinkedList_get
 *
 * Returns a void pointer to the element in the given index
 * of the given LinkedList. Returns NULL if LinkedList is empty
 *
 * CREs         list == NULL
 *              index out of bounds
 * UREs         getting an element that was previously freed
 *
 * @param       LinkedList_T    LinkedList containing queried
 *                              element
 * @param       unsigned        Index of element in LinkedList
 * @return      void *          void pointer to element
 */
void *LinkedList_get(LinkedList_T list, unsigned index);

/*
 * LinkedList_gethi
 *
 * Returns a void pointer to the element at index (length - 1)
 * of the given LinkedList. Returns NULL if LinkedList is empty
 *
 * CREs         list == NULL
 * UREs         getting an element that was previously freed
 *
 * @param       LinkedList_T    LinkedList containing queried
 *                              element
 * @return      void *          void pointer to element
 */
void *LinkedList_gethi(LinkedList_T list);

/*
 * LinkedList_getlo
 *
 * Returns a void pointer to the element at index 0 of the
 * given LinkedList. Returns NULL if LinkedList is empty
 *
 * CREs         list == NULL
 * UREs         getting an element that was previously freed
 *
 * @param       LinkedList_T    LinkedList containing queried
 *                              element
 * @return      void *          void pointer to element
 */
void *LinkedList_getlo(LinkedList_T list);

//////////////////////////////////
//      Setter Functions        //
//////////////////////////////////
/*
 * LinkedList_set
 *
 * Inserts the given element into the given index of the
 * LinkedList
 *
 * CREs         list == NULL
 *              index > length of listtor + 1
 * UREs         n/a
 *
 * @param       LinkedList_T    LinkedList in which to insert
 *                              element
 * @param       void *          Element to insert
 * @param       unsigned        Index of element in LinkedList
 * @return      n/a
 */
void LinkedList_set(LinkedList_T list, void *elem, unsigned index);

/*
 * LinkedList_sethi
 *
 * Inserts the given element into the end of the LinkedList
 *
 * CREs         list == NULL
 * UREs         n/a
 *
 * @param       LinkedList_T    LinkedList in which to insert
 *                              element
 * @param       void *          Element to insert
 * @return      n/a
 */
void LinkedList_sethi(LinkedList_T list, void *elem);

/*
 * LinkedList_setlo
 *
 * Inserts the given element into the front of the LinkedList
 *
 * CREs         list == NULL
 * UREs         n/a
 *
 * @param       LinkedList_T    LinkedList in which to insert
 *                              element
 * @param       void *          Element to insert
 * @return      n/a
 */
void LinkedList_setlo(LinkedList_T list, void *elem);

//////////////////////////////////
//      Remove Functions        //
//////////////////////////////////
/*
 * LinkedList_remove
 *
 * Removes the element at the given index in the LinkedList.
 * It is the client's responsibility to free the element
 * in the given index
 *
 * CREs         list == NULL
 * UREs         n/a
 *
 * @param       LinkedList_T    LinkedList containing queried
 *                              element
 * @param       unsigned        Index of element in LinkedList
 * @return      n/a
 */
void LinkedList_remove(LinkedList_T list, unsigned index);

/*
 * LinkedList_removehi
 *
 * Removes the element at the end of the LinkedList. It is
 * the client's responsibility to free the element in the
 * given index
 *
 * CREs         list == NULL
 * UREs         n/a
 *
 * @param       LinkedList_T    LinkedList containing queried
 *                              element
 * @return      n/a
 */
void LinkedList_removehi(LinkedList_T list);

/*
 * LinkedList_removelo
 *
 * Removes the element at the front of the LinkedList. It is
 * the client's responsibility to free the element in the
 * given index
 *
 * CREs         list == NULL
 * UREs         n/a
 *
 * @param       LinkedList_T    LinkedList containing queried
 *                              element
 * @return      n/a
 */
void LinkedList_removelo(LinkedList_T list);

#endif
