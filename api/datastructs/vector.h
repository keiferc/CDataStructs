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
 * a pointer to an instance of a Vector.
 * 
 * CREs         n/a
 * UREs         n/a
 * 
 * @param       int -           Hint of the default size of
 * 				the Vector
 * @return      Vector_T -      A pointer to an instance of
 * 				an expandable array
 */
Vector_T Vector_new(unsigned hint);

#endif
