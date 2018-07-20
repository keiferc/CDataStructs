/*
 *      filename:       vector.h
 *      author:         @keiferchiang
 *      date:           20 Jul 2018
 *      version:        0.0.1
 *
 *      description:    Interface for the Vector module
 */

/*-------------------------------------
 * C Preprocessor Directives
 -------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

#ifndef VECTOR_H_
#define VECTOR_H_

/*-------------------------------------
 * Representation
 -------------------------------------*/
typedef struct vector_t *Vector_T;

/*-------------------------------------
 * Function Prototypes
 -------------------------------------*/
/*
 * Vector_new
 *
 * Given a hint of the default size, creates and returns
 * a pointer to an instance of a Vector
 *
 * CREs         0 > hint >= INT_MAX
 * UREs         n/a
 *
 * @param       int             Hint of the default size of
 * 				the Vector
 * @return      Vector_T        A pointer to an instance of
 * 				an expandable array
 */
Vector_T Vector_new(int hint);

/*
 * Vector_free
 *
 * Recycles heap allocated memory for Vector. It is the client's
 * responsibility to free every element in the Vector before
 * freeing the Vector itself
 *
 * CREs         vec == NULL
 * UREs         elements in vec != NULL
 *
 * @param       Vector_T        Vector to be freed
 * @return      n/a
 */
void Vector_free(Vector_T *vec);

//////////////////////////////////
//      Getter Functions        //
//////////////////////////////////
/*
 * Vector_length
 *
 * Returns the length of the given Vector
 *
 * CREs         vec == NULL
 * UREs         n/a
 *
 * @param       Vector_T        Vector whose length is to
 *                              be returned
 * @return      int             Length of the Vector
 */
int Vector_length(Vector_T vec);

/*
 * Vector_get
 *
 * Returns a void pointer to the element in the given index
 * of the given Vector. Returns NULL if Vector is empty
 *
 * CREs         vec == NULL
 *              index out of bounds
 * UREs         getting an element that was previously freed
 *
 * @param       Vector_T        Vector containing queried
 *                              element
 * @param       int             Index of element in Vector
 * @return      void *          void pointer to element
 */
void *Vector_get(Vector_T vec, int index);

/*
 * Vector_last
 *
 * Returns a void pointer to the element at index (length - 1)
 * of the given Vector. Returns NULL if Vector is empty
 *
 * CREs         vec == NULL
 * UREs         getting an element that was previously freed
 *
 * @param       Vector_T        Vector containing queried
 *                              element
 * @return      void *          void pointer to element
 */
void *Vector_last(Vector_T vec);

/*
 * Vector_first
 *
 * Returns a void pointer to the element at index 0 of the
 * given Vector. Returns NULL if Vector is empty
 *
 * CREs         vec == NULL
 * UREs         getting an element that was previously freed
 *
 * @param       Vector_T        Vector containing queried
 *                              element
 * @return      void *          void pointer to element
 */
void *Vector_first(Vector_T vec);

//////////////////////////////////
//      Setter Functions        //
//////////////////////////////////
/*
 * Vector_set
 *
 * Inserts the given element into the given index of the
 * Vector. Valid indices range from 0 to length
 *
 * CREs         vec == NULL
 *              0 > index > length of vector + 1
 * UREs         n/a
 *
 * @param       Vector_T        Vector in which to insert
 *                              element
 * @param       void *          Element to insert
 * @param       int             Index of element in Vector
 * @return      n/a
 */
void Vector_set(Vector_T vec, void *elem, int index);

/*
 * Vector_append
 *
 * Inserts the given element into the end of the
 * Vector
 *
 * CREs         vec == NULL
 * UREs         n/a
 *
 * @param       Vector_T        Vector in which to insert
 *                              element
 * @param       void *          Element to insert
 * @return      n/a
 */
void Vector_append(Vector_T vec, void *elem);

/*
 * Vector_prepend
 *
 * Inserts the given element into the front of the
 * Vector
 *
 * CREs         vec == NULL
 * UREs         n/a
 *
 * @param       Vector_T        Vector in which to insert
 *                              element
 * @param       void *          Element to insert
 * @return      n/a
 */
void Vector_prepend(Vector_T vec, void *elem);

//////////////////////////////////
//      Remove Functions        //
//////////////////////////////////
/*
 * Vector_remove
 *
 * Removes the element at the given index in the Vector.
 * It is the client's responsibility to free the element
 * in the given index
 *
 * CREs         vec == NULL
 *              index out of bounds
 * UREs         n/a
 *
 * @param       Vector_T        Vector containing queried
 *                              element
 * @param       int             Index of element in Vector
 * @return      n/a
 */
void Vector_remove(Vector_T vec, int index);

/*
 * Vector_removehi
 *
 * Removes the element at the end of the Vector It is
 * the client's responsibility to free the element in
 * the given index
 *
 * CREs         vec == NULL
 * UREs         n/a
 *
 * @param       Vector_T        Vector containing queried
 *                              element
 * @return      n/a
 */
void Vector_removehi(Vector_T vec);

/*
 * Vector_removelo
 *
 * Removes the element at the front of the Vector. It
 * is the client's responsibility to free the element
 * in the given index
 *
 * CREs         vec == NULL
 * UREs         n/a
 *
 * @param       Vector_T        Vector containing queried
 *                              element
 * @return      n/a
 */
void Vector_removelo(Vector_T vec);

#endif
