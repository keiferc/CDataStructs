/*
 *      filename:       dlinkedlist.c
 *      author:         @keiferchiang
 *      date:           2 May 2018
 *      version:        0.0.1
 *
 *      description:    Interface of the DLinkedList module
 */
/*-------------------------------------
 * C Preprocessor Directives
 -------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#ifndef DLINKEDLIST_H_
#define DLINKEDLIST_H_

/*-------------------------------------
 * Representation
 -------------------------------------*/
typedef struct dlinkedlist_t *DLinkedList_T;

/*-------------------------------------
 * Function Prototypes
 -------------------------------------*/
/*
 * DLinkedList_new
 *
 * Given a hint of the default size, creates and returns
 * a pointer to an instance of a DLinkedList
 *
 * CREs         n/a
 * UREs         n/a
 *
 * @param       unsigned        Hint of the default size of
 * 				the DLinkedList
 * @return      DLinkedList_T    A pointer to an instance of
 * 				a linked-list
 */
DLinkedList_T DLinkedList_new(unsigned hint);

/*
 * DLinkedList_free
 *
 * Recycles heap allocated memory for DLinkedList. It is the
 * client's responsibility to free every element in the
 * DLinkedList before freeing the DLinkedList itself
 *
 * CREs         list == NULL
 * UREs         elements in list != NULL
 *
 * @param       DLinkedList_T    DLinkedList to be freed
 * @return      n/a
 */
void DLinkedList_free(DLinkedList_T *list);

//////////////////////////////////
//      Getter Functions        //
//////////////////////////////////
/*
 * DLinkedList_length
 *
 * Returns the length of the given DLinkedList
 *
 * CREs         list == NULL
 * UREs         n/a
 *
 * @param       DLinkedList_T    DLinkedList whose length is to
 *                              be returned
 * @return      unsigned        Length of the DLinkedList
 */
unsigned DLinkedList_length(DLinkedList_T list);

/*
 * DLinkedList_get
 *
 * Returns a void pointer to the element in the given index
 * of the given DLinkedList. Returns NULL if DLinkedList is empty
 *
 * CREs         list == NULL
 *              index out of bounds
 * UREs         getting an element that was previously freed
 *
 * @param       DLinkedList_T    DLinkedList containing queried
 *                              element
 * @param       unsigned        Index of element in DLinkedList
 * @return      void *          void pointer to element
 */
void *DLinkedList_get(DLinkedList_T list, unsigned index);

/*
 * DLinkedList_gethi
 *
 * Returns a void pointer to the element at index (length - 1)
 * of the given DLinkedList. Returns NULL if DLinkedList is empty
 *
 * CREs         list == NULL
 * UREs         getting an element that was previously freed
 *
 * @param       DLinkedList_T   DLinkedList containing queried
 *                              element
 * @return      void *          void pointer to element
 */
void *DLinkedList_gethi(DLinkedList_T list);

/*
 * DLinkedList_getlo
 *
 * Returns a void pointer to the element at index 0 of the
 * given DLinkedList. Returns NULL if DLinkedList is empty
 *
 * CREs         list == NULL
 * UREs         getting an element that was previously freed
 *
 * @param       DLinkedList_T   DLinkedList containing queried
 *                              element
 * @return      void *          void pointer to element
 */
void *DLinkedList_getlo(DLinkedList_T list);

//////////////////////////////////
//      Setter Functions        //
//////////////////////////////////
/*
 * DLinkedList_set
 *
 * Inserts the given element into the given index of the
 * DLinkedList
 *
 * CREs         list == NULL
 *              index > length of list
 * UREs         n/a
 *
 * @param       DLinkedList_T   DLinkedList in which to insert
 *                              element
 * @param       void *          Element to insert
 * @param       unsigned        Index of element in DLinkedList
 * @return      n/a
 */
void DLinkedList_set(DLinkedList_T list, void *elem, unsigned index);

/*
 * DLinkedList_sethi
 *
 * Inserts the given element into the end of the DLinkedList
 *
 * CREs         list == NULL
 * UREs         n/a
 *
 * @param       DLinkedList_T   DLinkedList in which to insert
 *                              element
 * @param       void *          Element to insert
 * @return      n/a
 */
void DLinkedList_sethi(DLinkedList_T list, void *elem);

/*
 * DLinkedList_setlo
 *
 * Inserts the given element into the front of the DLinkedList
 *
 * CREs         list == NULL
 * UREs         n/a
 *
 * @param       DLinkedList_T   DLinkedList in which to insert
 *                              element
 * @param       void *          Element to insert
 * @return      n/a
 */
void DLinkedList_setlo(DLinkedList_T list, void *elem);

//////////////////////////////////
//      Remove Functions        //
//////////////////////////////////
/*
 * DLinkedList_remove
 *
 * Removes the element at the given index in the DLinkedList.
 * It is the client's responsibility to free the element
 * in the given index
 *
 * CREs         list == NULL
 * UREs         n/a
 *
 * @param       DLinkedList_T   DLinkedList containing queried
 *                              element
 * @param       unsigned        Index of element in DLinkedList
 * @return      n/a
 */
void DLinkedList_remove(DLinkedList_T list, unsigned index);

/*
 * DLinkedList_removehi
 *
 * Removes the element at the end of the DLinkedList. It is
 * the client's responsibility to free the element in the
 * given index
 *
 * CREs         list == NULL
 * UREs         n/a
 *
 * @param       DLinkedList_T   DLinkedList containing queried
 *                              element
 * @return      n/a
 */
void DLinkedList_removehi(DLinkedList_T list);

/*
 * DLinkedList_removelo
 *
 * Removes the element at the front of the DLinkedList. It is
 * the client's responsibility to free the element in the
 * given index
 *
 * CREs         list == NULL
 * UREs         n/a
 *
 * @param       DLinkedList_T   DLinkedList containing queried
 *                              element
 * @return      n/a
 */
void DLinkedList_removelo(DLinkedList_T list);

#endif
