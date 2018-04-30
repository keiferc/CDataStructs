/*
 *      filename:       vector.h
 *      author:         @keiferchiang
 *      date:           23 Apr. 2018
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
#include <stdint.h>
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
 * CREs         n/a
 * UREs         n/a
 *
 * @param       int             Hint of the default size of
 * 				the Vector
 * @return      Vector_T        A pointer to an instance of
 * 				an expandable array
 */
Vector_T Vector_new(unsigned hint);

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

////////////////////////////////////////////
//-----------------TODO-------------------//
////////////////////////////////////////////
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
 * @return      unsigned        Length of the Vector
 */
unsigned Vector_length(Vector_T vec);

/*
 * Vector_at
 *
 * Returns a void pointer to the element in the given index
 * of the given Vector. The client can use this function to
 * both put and retrieve the element at the given index
 *
 * CREs         vec == NULL
 * UREs         n/a
 *
 * @param       Vector_T        Vector containing queried
 *                              element
 * @param       unsigned        Index of element in Vector
 * @return      void *          void pointer to element
 */
void *Vector_at(Vector_T vec, unsigned index);

/*
 * Vector_hi
 *
 * Returns a void pointer to the element at index (length - 1)
 * of the given Vector
 *
 * CREs         vec == NULL
 * UREs         n/a
 *
 * @param       Vector_T        Vector containing queried
 *                              element
 * @return      void *          void pointer to element
 */
void *Vector_hi(Vector_T vec);

/*
 * Vector_lo
 *
 * Returns a void pointer to the element at index 0 of the
 * given Vector
 *
 * CREs         vec == NULL
 * UREs         n/a
 *
 * @param       Vector_T        Vector containing queried
 *                              element
 * @return      void *          void pointer to element
 */
void *Vector_lo(Vector_T vec);

#endif
